cmake_minimum_required(VERSION 3.6)
project(Enigma.Window C)

set(DYNAMIC false)
set(CMAKE_C_STANDARD 99)
set(GLFW true)
set(SOURCES WindowModule.c)

if (DYNAMIC)
    add_library(Enigma.Window SHARED ${SOURCES})
else()
    add_library(Enigma.Window STATIC ${SOURCES})
endif()

if (GLFW)
    add_subdirectory(glfw)
endif()
