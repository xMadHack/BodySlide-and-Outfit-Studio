#pragma once



enum class OSMethods {
    NONE = 0, OUTFIT_STUDIO_OPENED = 1

};

typedef void(__stdcall* outfit_studio_callback)(OSMethods);


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


#ifdef __cplusplus
}
#endif

