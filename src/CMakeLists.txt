cmake_minimum_required(VERSION 3.6)
project(Enigma.Window C)

set(ENIGMA_WINDOW_DLL OFF CACHE BOOL "Build shared lib instead of static" FORCE)
set(CMAKE_C_STANDARD 99)
set(ENIGMA_GLFW ON CACHE BOOL "Enable build of Glfw module" FORCE)

file(GLOB SOURCES private/*.c)

if (ENIGMA_WINDOW_DLL)
    add_library(Enigma.Window SHARED ${SOURCES})
else()
    add_library(Enigma.Window STATIC ${SOURCES})
endif()
target_include_directories(Enigma.Window PRIVATE private/)
target_include_directories(Enigma.Window INTERFACE public/)

if (ENIGMA_GLFW)
    add_compile_definitions(ENIGMA_GLFW)
    add_subdirectory(glfw)
endif()
