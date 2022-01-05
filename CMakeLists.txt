cmake_minimum_required(VERSION 3.6)

option(BUILD_TEST "Build test directory" ON)

add_subdirectory(src)

if (BUILD_TEST)
	add_subdirectory(test)
endif()