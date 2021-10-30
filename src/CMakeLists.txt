cmake_minimum_required(VERSION 3.6)
project(Enigma.Window C)

set(ENIGMA_WINDOW_DLL OFF CACHE BOOL "" FORCE)
set(CMAKE_C_STANDARD 99)
set(ENIGMA_GLFW ON CACHE BOOL "" FORCE)
set(SOURCES WindowModule.c)

if (ENIGMA_WINDOW_DLL)
    add_library(Enigma.Window SHARED ${SOURCES})
else()
    add_library(Enigma.Window STATIC ${SOURCES})
endif()

if (ENIGMA_GLFW)
    add_compile_definitions(ENIGMA_GLFW)
    add_subdirectory(glfw)
endif()
