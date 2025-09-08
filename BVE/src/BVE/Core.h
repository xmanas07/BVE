#pragma once

#ifdef BVE_PLATFORM_WINDOWS
	#ifdef BVE_BUILD_DLL
		#define BVE_API __declspec(dllexport)
	#else
		#define BVE_API __declspec(dllimport)
	#endif
#else
	#error BVE only supports Windows!
#endif