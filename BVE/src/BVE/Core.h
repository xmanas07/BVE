#pragma once
/*
* Checks the platform
* creates macro for the __declspec(dllexport) and __declspec(dllimport) keyword
* BVE preprocessor defines BVE_BUILD_DLL so if BVE is building BVE_API will get translated to __declspec(dllexport)
* else to __declspec(dllimport)
*/
#ifdef BVE_PLATFORM_WINDOWS
	#ifdef BVE_BUILD_DLL
		#define BVE_API __declspec(dllexport)
	#else
		#define BVE_API __declspec(dllimport)
	#endif
#else
	#error BVE only supports Windows!
#endif