cmake_minimum_required(VERSION 3.6)
project(Enigma.Glfw C)

# Setup glfw library
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfwlib)
include_directories(Enigma.Glfw glfwlib/include)
# End of setup

set(ENIGMA_GLFW_DLL OFF CACHE BOOL "" FORCE)
set(CMAKE_C_STANDARD 99)
set(SOURCES GlfwWindow.c GlfwWindow.h GlfwModule.c GlfwModule.h)

include_directories(Enigma.Glfw ../) # include Enigma.Window headers

if (ENIGMA_GLFW_DLL)
    add_library(Enigma.Glfw SHARED ${SOURCES})
else()
    add_library(Enigma.Glfw STATIC ${SOURCES})
endif()

target_link_libraries(Enigma.Glfw PRIVATE glfw)
target_link_libraries(Enigma.Glfw PUBLIC Enigma.Window)