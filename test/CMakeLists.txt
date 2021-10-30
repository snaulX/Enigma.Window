cmake_minimum_required(VERSION 3.6)
project(Enigma.Window.Tests C)

set(CMAKE_C_STANDARD 99)

add_executable(Enigma.Window.Tests main.c)

target_link_libraries(Enigma.Window.Tests PUBLIC Enigma.Glfw)

include_directories(Enigma.Window.Tests ../src)
include_directories(Enigma.Window.Tests ../src/glfw/glfwlib/include)
