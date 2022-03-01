cmake_minimum_required(VERSION 3.6)
project(Enigma.Window C)

set(ENIGMA_WINDOW_DLL OFF CACHE BOOL "Build shared lib instead of static")
set(CMAKE_C_STANDARD 99)
set(ENIGMA_GLFW OFF CACHE BOOL "Enable build of Glfw module")

set(SOURCES private/WindowModule.c private/NativeWindow.c private/ErrorCallback.c)

if (ENIGMA_WINDOW_DLL)
    add_library(Enigma.Window SHARED ${SOURCES})
else()
    add_library(Enigma.Window STATIC ${SOURCES})
endif()
target_include_directories(Enigma.Window PRIVATE private/)
target_include_directories(Enigma.Window INTERFACE interface/)

set(ENIGMA_WINDOW_BUILD_TESTS ON CACHE BOOL "Build tests for Enigma.Window")
if (ENIGMA_WINDOW_BUILD_TESTS)
    message(STATUS "Build tests of Enigma.Window")
    add_subdirectory(test)
endif()

if (ENIGMA_GLFW)
    message(STATUS "Build Enigma.Glfw module")
    add_compile_definitions(ENIGMA_GLFW)
    add_subdirectory(glfw)
endif()
