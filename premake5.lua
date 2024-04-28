include "deps/Dependencies.lua"

workspace "Lila"
    linkgroups "On"
    warnings "Off"

    architecture "x64"
    startproject "Testbed"

    configurations { "Debug", "Release" }
    
OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Dependencies"
    include "deps/glad"
group ""

group "GLFW"
    include "deps/glfw"
group ""

group "Lila engine"
    include "Lila/build.lua"
group ""

group "Testing"
    include "testbed/build.lua"
group ""
