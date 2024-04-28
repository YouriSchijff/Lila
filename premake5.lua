include "deps/Dependencies.lua"

newoption {
   trigger = "headless",
   description = "Removes every rendering component"
}

workspace "Lila"
    linkgroups "On"
    warnings "Off"

    architecture "x64"
    startproject "Testbed"

    configurations { "Debug", "Release" }
    
OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
    include "deps/glad"
    include "deps/glfw"
group ""

include "Lila/build.lua"
include "testbed/build.lua"
