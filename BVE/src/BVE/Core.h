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

#ifdef BVE_ENABLE_ASSERTS
	#define BVE_ASSERT(x, ...) {if(!(x)) {BVE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
	#define BVE_CORE_ASSERT(x, ...) {if(!(x)) {BVE_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}}
#else
	#define BVE_ASSERT(x, ...)
	#define BVE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)