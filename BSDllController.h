#pragma once

#include "BodySlideDll.h"

class BodySlideApp;
class BodySlideFrame;

class BSDllController {
public:
    static BodySlideApp* body_slide_app_instance;
    static BodySlideFrame* body_slide_frame_instance;
    static callback_action bs_event_handler;
    static void set_event_handler(callback_action act);
    static void raise_event(BSMethods method);
};
