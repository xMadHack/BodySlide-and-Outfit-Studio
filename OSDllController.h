#pragma once

#include "OutfitStDll.h"
#include "COutfitStudioMethodsInclude.h"


class OutfitStudio;
class OutfitStudioFrame;
namespace xmadhack_c {
    class OSDllController {
    public:
        static OutfitStudio* outfit_studio_app_instance;
        static OutfitStudioFrame* outfit_studio_frame_instance;
        static outfit_studio_callback os_event_handler;
        static void set_event_handler(outfit_studio_callback act);
        static void raise_event(OSMethods method);

        static void perform(COutfitStudioMethods method);
    };
}