#include "BSDllController.h"

#ifndef NULL 
#define NULL 0
#endif // !NULL 

using namespace xmadhack_c;

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

int BSDllController::read_int(CBodySlideProperties prop)
{
	switch (prop)
	{
	case CBodySlideProperties::TestProperty:
		return 123;
	default:
		break;
	}
	throw std::exception("Invalid int BS property");
}

std::string BSDllController::read_string(CBodySlideProperties prop)
{
	switch (prop)
	{
	case CBodySlideProperties::TestProperty:
		return "TEST_STRING";
	default:
		break;
	}
	throw std::exception("Invalid string BS property");
}

std::vector<std::string> BSDllController::read_string_array(CBodySlideProperties prop)
{
	switch (prop)
	{
	case CBodySlideProperties::BatchList:
		break;
	case CBodySlideProperties::TestProperty: {
		std::vector<std::string> test_str_arr = { "A", " TEST ", "STRING" };
		return test_str_arr;
	}
	default:
		break;
	}
	throw std::exception("Invalid string array BS property");

}
