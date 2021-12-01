cmake_minimum_required(VERSION 3.6)
project(Enigma.Glfw C)

# Setup glfw library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfwlib)
# End of setup

set(ENIGMA_GLFW_DLL OFF CACHE BOOL "Build shared lib instead of static" FORCE)
set(CMAKE_C_STANDARD 99)
set(SOURCES GlfwWindow.c GlfwWindow.h GlfwModule.c GlfwModule.h)

if (ENIGMA_GLFW_DLL)
    add_library(Enigma.Glfw SHARED ${SOURCES})
else()
    add_library(Enigma.Glfw STATIC ${SOURCES})
endif()

target_include_directories(Enigma.Glfw PRIVATE glfwlib/include)
target_link_libraries(Enigma.Glfw PRIVATE glfw)

target_include_directories(Enigma.Glfw PUBLIC ../) # include Enigma.Window header
target_link_libraries(Enigma.Glfw PUBLIC Enigma.Window)