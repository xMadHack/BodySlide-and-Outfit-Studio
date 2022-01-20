#pragma once

#include <Windows.h>



namespace xmadhack_c {
    enum class COutfitStudioMethods;
    enum class COutfitStudioEvents;

}

typedef void(__stdcall* outfit_studio_callback)(xmadhack_c::COutfitStudioEvents);


#ifdef __cplusplus
extern "C" {
#endif

#ifdef MY_DLL_BUILDING
#define MY_DLL_DECL __declspec(dllexport)
#else
#define MY_DLL_DECL __declspec(dllimport)
#endif


    /*typedef int(__stdcall* ANSWERCB)(int, int);*/

    MY_DLL_DECL void launch_outfit_studio();
    MY_DLL_DECL bool is_outfit_studio_running();

    void outfit_studio_closed();

    //MY_DLL_DECL int TakesCallback(ANSWERCB fp, int n, int m);
    MY_DLL_DECL void set_outfit_studio_event_handler(outfit_studio_callback act);

    MY_DLL_DECL void os_perform(xmadhack_c::COutfitStudioMethods method); 
    MY_DLL_DECL void os_perform_str(xmadhack_c::COutfitStudioMethods method, LPCTSTR arg);
#ifdef __cplusplus
}
#endif

