//#include "src/program/BodySlideApp.h"
//#include "BodySlideDll.h"
//Do not include BSFrameMethods.h here
//
//
//
//
//void ClickSettings() {
//	BSDllInterface::body_slide_app_instance->CallAfter<BodySlideFrame>(&BodySlideFrame::publicOpenSettings);
//	//BodySlideFrame::instance->publicOpenSettings();
////}
//
//void DoBSFrameMethod(BSMethods method, void* action)
//{
//	//callback_action act = (callback_action)action;
//	//BodySlideFrame::instance->DoMethod(method, act);
//}
//
////int TakesCallback(ANSWERCB fp, int n, int m) {
////	/*printf_s("[unmanaged] got callback address, calling it...\n");*/
////	return fp(n, m);
////}
//
//void BodySlideFrame::publicOpenSettings()
//{
//	BodySlideFrame::OnSettings((wxCommandEvent&)wxCommandEvent(NULL, 0));
//}

//void BodySlideFrame::DoMethod(BSMethods method, callback_action callback) {
//	BodySlideApp::instance->CallAfter(&BodySlideFrame::pDoMethod, method, callback);
//}
//
//
//void BodySlideFrame::pDoMethod(BSMethods method, callback_action callback) {
//	switch (method) {
//	case BSMethods::NONE: break;
//	case BSMethods::OPEN_SETTINGS: this->OnSettings((wxCommandEvent&)wxCommandEvent()); break;
//	}
//	callback();
//}