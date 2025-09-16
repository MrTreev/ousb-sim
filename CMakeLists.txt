cmake_minimum_required(VERSION 4.0)
project(OusbSim
		VERSION 0.0.0
		DESCRIPTION "OUSB board simulator"
		LANGUAGES CXX
)

include(FetchContent)
set(IMGUI_VERSION "1.92.2b")
FetchContent_Declare(
    imgui
    URL https://github.com/ocornut/imgui/archive/refs/tags/v${IMGUI_VERSION}-docking.tar.gz
)
FetchContent_Declare(rlimgui
    GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git
    GIT_TAG 4d8a61842903978bc42adf3347cd34f4e6524efc
)
FetchContent_Declare(raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_MakeAvailable(imgui)
FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(rlimgui)
add_library(imgui
    STATIC  ${imgui_SOURCE_DIR}/imgui.cpp
            ${imgui_SOURCE_DIR}/imgui_demo.cpp
            ${imgui_SOURCE_DIR}/imgui_draw.cpp
            ${imgui_SOURCE_DIR}/imgui_tables.cpp
            ${imgui_SOURCE_DIR}/imgui_widgets.cpp
            ${rlimgui_SOURCE_DIR}/rlImGui.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
target_include_directories(imgui PUBLIC ${rlimgui_SOURCE_DIR})
target_include_directories(imgui PUBLIC ${raylib_SOURCE_DIR}/src)

add_subdirectory(src)
