#include "OSDllController.h"

#ifndef NULL 
#define NULL 0
#endif // !NULL 


outfit_studio_callback OSDllController::os_event_handler = NULL;
OutfitStudio* OSDllController::outfit_studio_app_instance = NULL;
OutfitStudioFrame* OSDllController::outfit_studio_frame_instance = NULL;

void OSDllController::set_event_handler(outfit_studio_callback act)
{
	OSDllController::os_event_handler = act;
}

void OSDllController::raise_event(OSMethods method)
{
	if (OSDllController::os_event_handler != NULL) OSDllController::os_event_handler(method);
}
