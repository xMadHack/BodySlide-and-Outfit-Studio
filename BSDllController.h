#pragma once

#include "BodySlideDll.h"
#include "CBodySlidePropertiesInclude.h"
#include <string>
#include <vector>

class BodySlideApp;
class BodySlideFrame;

namespace xmadhack_c {
    class BSDllController {
    public:
        static BodySlideApp* body_slide_app_instance;
        static BodySlideFrame* body_slide_frame_instance;
        static callback_action bs_event_handler;
        static void set_event_handler(callback_action act);
        static void raise_event(BSMethods method);
        /*Properties return native objects*/
        static int read_int(CBodySlideProperties prop);
        static std::string read_string(CBodySlideProperties prop);
        static std::vector<std::string> read_string_array(CBodySlideProperties prop);
    };
}

