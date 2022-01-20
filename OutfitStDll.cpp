#include "wx/wxprec.h"

#include "wx/app.h"
#include "wx/dynlib.h"
#include "wx/frame.h"
#include "wx/panel.h"
#include "wx/sizer.h"
#include "wx/stattext.h"
#include "wx/button.h"
#include "wx/thread.h"
#include "wx/msgdlg.h"
#include "wx/msw/wrapwin.h"

#include <process.h> // for _beginthreadex()

#include "OutfitStDll.h"
#include "OSDllController.h"
#include "src/program/OutfitStudio.h"




using namespace xmadhack_c;

// ----------------------------------------------------------------------------
// application startup
// ----------------------------------------------------------------------------

// we can't have WinMain() in a DLL and want to start the app ourselves
wxIMPLEMENT_APP_NO_MAIN(OutfitStudio);

namespace
{

	// Critical section that guards everything related to wxWidgets "main" thread
	// startup or shutdown.
	wxCriticalSection gs_wxStartupCS;
	// Handle of wx "main" thread if running, NULL otherwise
	HANDLE gs_wxMainThread = NULL;


	//  wx application startup code -- runs from its own thread
	unsigned wxSTDCALL MyAppLauncher(void* event)
	{
		// Note: The thread that called run_wx_gui_from_dll() holds gs_wxStartupCS
		//       at this point and won't release it until we signal it.

		// We need to pass correct HINSTANCE to wxEntry() and the right value is
		// HINSTANCE of this DLL, not of the main .exe, use this MSW-specific wx
		// function to get it. Notice that under Windows XP and later the name is
		// not needed/used as we retrieve the DLL handle from an address inside it
		// but you do need to use the correct name for this code to work with older
		// systems as well.

#ifdef _DEBUG
		const HINSTANCE
			hInstance = wxDynamicLibrary::MSWGetModuleHandle("OutfitStudio x64 Debug",
				&gs_wxMainThread);
#else
		const HINSTANCE
			hInstance = wxDynamicLibrary::MSWGetModuleHandle("OutfitStudio x64 Release",
				&gs_wxMainThread);
#endif // _DEBUG



		if (!hInstance)
			return 0; // failed to get DLL's handle

		// wxIMPLEMENT_WXWIN_MAIN does this as the first thing
		wxDISABLE_DEBUG_SUPPORT();

		// We do this before wxEntry() explicitly, even though wxEntry() would
		// do it too, so that we know when wx is initialized and can signal
		// run_wx_gui_from_dll() about it *before* starting the event loop.
		wxInitializer wxinit;
		if (!wxinit.IsOk())
			return 0; // failed to init wx

		// Signal run_wx_gui_from_dll() that it can continue
		HANDLE hEvent = *(static_cast<HANDLE*>(event));
		if (!SetEvent(hEvent))
			return 0; // failed setting up the mutex

		// Run the app:
		wxEntry(hInstance);

		return 1;
	}

} // anonymous namespace

// ----------------------------------------------------------------------------
// public DLL interface
// ----------------------------------------------------------------------------

extern "C"
{

	void run_wx_gui_from_dll(const char* title)
	{
		// In order to prevent conflicts with hosting app's event loop, we
		// launch wx app from the DLL in its own thread.
		//
		// We can't even use wxInitializer: it initializes wxModules and one of
		// the modules it handles is wxThread's private module that remembers
		// ID of the main thread. But we need to fool wxWidgets into thinking that
		// the thread we are about to create now is the main thread, not the one
		// from which this function is called.
		//
		// Note that we cannot use wxThread here, because the wx library wasn't
		// initialized yet. wxCriticalSection is safe to use, though.

		wxCriticalSectionLocker lock(gs_wxStartupCS);

		if (!gs_wxMainThread)
		{
			HANDLE hEvent = CreateEvent
			(
				NULL,  // default security attributes
				FALSE, // auto-reset
				FALSE, // initially non-signaled
				NULL   // anonymous
			);
			if (!hEvent)
				return; // error

			// NB: If your compiler doesn't have _beginthreadex(), use CreateThread()
			gs_wxMainThread = (HANDLE)_beginthreadex
			(
				NULL,           // default security
				0,              // default stack size
				&MyAppLauncher,
				&hEvent,        // arguments
				0,              // create running
				NULL
			);

			if (!gs_wxMainThread)
			{
				CloseHandle(hEvent);
				return; // error
			}

			// Wait until MyAppLauncher signals us that wx was initialized. This
			// is because we use wxMessageQueue<> and wxString later and so must
			// be sure that they are in working state.
			WaitForSingleObject(hEvent, INFINITE);
			CloseHandle(hEvent);
		}

		// Send a message to wx thread to show a new frame:
	   /* wxThreadEvent* event =
			new wxThreadEvent(wxEVT_THREAD, CMD_SHOW_WINDOW);
		event->SetString(title);
		wxQueueEvent(wxTheApp, event);*/
	}

	void launch_outfit_studio() {
		outfit_studio_closed();
		run_wx_gui_from_dll("OutfitStudio");
	}

	void outfit_studio_closed() {
		wxCriticalSectionLocker lock(gs_wxStartupCS);
		if (!gs_wxMainThread)
			return;
		CloseHandle(gs_wxMainThread);
		gs_wxMainThread = NULL;
	}

	void set_outfit_studio_event_handler(outfit_studio_callback act)
	{
		OSDllController::set_event_handler(act);
	}

	 void os_perform(xmadhack_c::COutfitStudioMethods method)
	{
		 OSDllController::perform(method);
	}

	bool is_outfit_studio_running() {
		return (gs_wxMainThread != NULL);
	}


} // extern "C"

