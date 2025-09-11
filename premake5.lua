

workspace "BVE"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	filter "action:vs*"
		buildoptions {"/utf-8"}
	filter {}

	project "BVE"
		location "BVE"
		kind "SharedLib"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "bvepch.h"
		pchsource "BVE/src/bvepch.cpp"

		files 
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			
			"%{prj.name}/src",
			"%{prj.name}/vendor/spdlog/include"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines 
			{
				"BVE_PLATFORM_WINDOWS",
				"BVE_BUILD_DLL"
			}

			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Debug"
			defines "BVE_DEBUG"
			symbols "On"
	
		filter "configurations:Release"
			defines "BVE_RELEASE"
			optimize "On"
	
		filter "configurations:Dist"
			defines "BVE_DIST"
			optimize "On"
	
	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files 
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"BVE/vendor/spdlog/include",
			"BVE/src"
		}

		links
		{
			"BVE"
		}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "On"
			systemversion "latest"

			defines 
			{
				"BVE_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "BVE_DEBUG"
			symbols "On"
	
		filter "configurations:Release"
			defines "BVE_RELEASE"
			optimize "On"
	
		filter "configurations:Dist"
			defines "BVE_DIST"
			optimize "On"