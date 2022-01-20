// Dont use any include guard in this file, and dont include it anywhere. (DO NOT #pragma once)
// The namespace is defined in the .h file that includes this one.
#ifdef BSOSINTEROP_SIDE
public enum class OutfitStudioMethods
#else
enum class COutfitStudioMethods : int
#endif
{
	Unknown = 0, OpenProject=1, TestMethod = 999 /*Doesn't read form the app and always returns something*/
};
