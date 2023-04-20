#pragma once

#ifdef GF_PLATFORM_WINDOWS
	#ifdef GF_BUILD_DLL
		#define GFORGE_API __declspec(dllexport)
	#else
		#define GFORGE_API __declspec(dllimport)
	#endif
#else
	#error GForge only support Windows!
#endif