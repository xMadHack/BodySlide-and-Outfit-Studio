// Dont use any include guard in this file, and dont include it anywhere. (DO NOT #pragma once)
// The namespace is defined in the .h file that includes this one.
#ifdef BSOSINTEROP_SIDE
public enum class OutfitStudioEvents
#else
enum class COutfitStudioEvents : int
#endif
{
	Unknown = 0, 
	OutfitStudioOpened=1, 
	ProjectLoaded = 2, 
	IntProjectLoaded = 3, /*Not raised by OS, but the controller*/
	TestEvent = 999 /*Doesn't read form the app and always returns something*/
};
