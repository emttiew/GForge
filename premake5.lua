workspace "GForge"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "GForge/vendor/GLFW/include"

include "GForge/vendor/GLFW"

project "GForge"
	location "GForge"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GF_PLATFORM_WINDOWS",
			"GF_BUILD_DLL",
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	
	filter "configurations:Debug"
		defines "GF_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "GF_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "GF_DIST"
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
		"GForge/vendor/spdlog/include",
		"GForge/src"
	}

	links
	{
		"GForge"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GF_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "GF_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "GF_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "GF_DIST"
		optimize "On"