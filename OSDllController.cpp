#include "OSDllController.h"

#include "src/program/OutfitStudio.h"
#include <wx/event.h>

#ifndef NULL 
#define NULL 0
#endif // !NULL 


using namespace xmadhack_c;

outfit_studio_callback OSDllController::os_event_handler = NULL;
OutfitStudio* OSDllController::outfit_studio_app_instance = NULL;
OutfitStudioFrame* OSDllController::outfit_studio_frame_instance = NULL;

void OSDllController::set_event_handler(outfit_studio_callback act)
{
	OSDllController::os_event_handler = act;
}

void OSDllController::raise_event(COutfitStudioEvents evnt)
{
	if (OSDllController::os_event_handler != NULL) OSDllController::os_event_handler(evnt);
}

void xmadhack_c::OSDllController::perform(COutfitStudioMethods method)
{
	switch (method)
	{
	case xmadhack_c::COutfitStudioMethods::Unknown:
		break;
	case xmadhack_c::COutfitStudioMethods::TestMethod:
		break;
	default:
		break;
	}
}

void xmadhack_c::OSDllController::perform(COutfitStudioMethods method, std::string arg)
{

	switch (method)
	{
	case xmadhack_c::COutfitStudioMethods::OpenProject:
		
		outfit_studio_app_instance->CallAfter([arg] {
			outfit_studio_frame_instance->LoadProject(arg);
			raise_event(COutfitStudioEvents::IntProjectLoaded);
			});

		break;
	case xmadhack_c::COutfitStudioMethods::TestMethod:
		break;
	default:
		break;
	}
}
