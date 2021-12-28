#pragma once

#include <string>
#include <vector>
#include <Windows.h>

enum class BSMethods {
    NONE=0, OPEN_SETTINGS=1, OPEN_OUTFIT_STUDIO=2

};

typedef void(__stdcall* callback_action)(BSMethods);
namespace xmadhack_c {
    enum class CBodySlideProperties;
}

//typedef void(__stdcall* read_int_property_function)(int);
//typedef void(__stdcall* read_string_property_function)(LPCTSTR str);
//typedef void(__stdcall* read_string_array_property_function)(std::vector<std::string>);

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

    MY_DLL_DECL void bs_free(void* p);
    MY_DLL_DECL void bs_delete_string(LPCTSTR p);

    MY_DLL_DECL void bs_read_int_property(xmadhack_c::CBodySlideProperties property, int * res);
    MY_DLL_DECL void bs_read_int_array_property(xmadhack_c::CBodySlideProperties property, int**data, int * arrayLenght);
    MY_DLL_DECL void  bs_read_string_property(xmadhack_c::CBodySlideProperties property, LPCTSTR*res);
    MY_DLL_DECL void  bs_read_string_array_property(xmadhack_c::CBodySlideProperties property, LPCTSTR**data, int * arrayLength);
    /*MY_DLL_DECL LPCTSTR  bs_read_string_array_property_at(BodySlideProperties property, int index);
    MY_DLL_DECL double  bs_read_double_property(BodySlideProperties property);
    MY_DLL_DECL int  bs_read_double_array_property_length(BodySlideProperties property);
    MY_DLL_DECL double  bs_read_double_array_property_at(BodySlideProperties property, int index);
    MY_DLL_DECL bool bs_read_bool_property(BodySlideProperties property);
    MY_DLL_DECL int bs_read_bool_array_property_length(BodySlideProperties property);
    MY_DLL_DECL bool bs_read_bool_array_property_at(BodySlideProperties property, int index);*/

#ifdef __cplusplus
}
#endif

