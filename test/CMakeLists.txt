cmake_minimum_required(VERSION 3.6)
project(Enigma.Window.Tests C)

set(CMAKE_C_STANDARD 99)
set(ENIGMA_GLFW ON PARENT_SCOPE)

add_executable(Enigma.Window.Tests main.c)

target_link_libraries(Enigma.Window.Tests PRIVATE Enigma.Glfw)
