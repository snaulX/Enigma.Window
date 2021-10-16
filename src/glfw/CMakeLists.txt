cmake_minimum_required(VERSION 3.6)
project(Enigma.Glfw C)

set(DYNAMIC false)
set(CMAKE_C_STANDARD 99)
set(SOURCES GlfwWindow.c GlfwWindow.h GlfwModule.c GlfwModule.h)

include_directories(Enigma.Glfw ../)

if (DYNAMIC)
    add_library(Enigma.Glfw SHARED ${SOURCES})
else()
    add_library(Enigma.Glfw STATIC ${SOURCES})
endif ()