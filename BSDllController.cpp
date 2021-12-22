#include "BSDllController.h"

#ifndef NULL 
#define NULL 0
#endif // !NULL 


callback_action BSDllController::bs_event_handler = NULL;
BodySlideApp* BSDllController::body_slide_app_instance = NULL;
BodySlideFrame* BSDllController::body_slide_frame_instance = NULL;

void BSDllController::set_event_handler(callback_action act)
{
	BSDllController::bs_event_handler = act;
}

void BSDllController::raise_event(BSMethods method)
{
	if (BSDllController::bs_event_handler != NULL) BSDllController::bs_event_handler(method);
}
