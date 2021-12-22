#pragma once



enum class BSMethods {
    NONE=0, OPEN_SETTINGS=1, OPEN_OUTFIT_STUDIO=2

};

typedef void(__stdcall* callback_action)(BSMethods);


#ifdef __cplusplus
extern "C" {
#endif

#ifdef MY_DLL_BUILDING
#define MY_DLL_DECL __declspec(dllexport)
#else
#define MY_DLL_DECL __declspec(dllimport)
#endif


    /*typedef int(__stdcall* ANSWERCB)(int, int);*/

    MY_DLL_DECL void launch_bodyslide();
    MY_DLL_DECL bool is_bodyslide_running();

    void bodyslide_closed();

    //MY_DLL_DECL int TakesCallback(ANSWERCB fp, int n, int m);
    MY_DLL_DECL void set_body_slide_event_handler(callback_action act);

    MY_DLL_DECL void ClickSettings();


#ifdef __cplusplus
}
#endif

