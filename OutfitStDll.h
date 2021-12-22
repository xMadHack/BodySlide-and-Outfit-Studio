#pragma once
//enum class OSFrameMethodsList;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef MY_DLL_BUILDING
#define MY_DLL_DECL __declspec(dllexport)
#else
#define MY_DLL_DECL __declspec(dllimport)
#endif

    MY_DLL_DECL void launch_outfit_studio();
    MY_DLL_DECL bool is_outfit_studio_running();

    void outfit_studio_closed();

#ifdef __cplusplus
}

#endif
