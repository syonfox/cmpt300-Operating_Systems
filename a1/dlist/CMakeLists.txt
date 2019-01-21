cmake_minimum_required(VERSION 3.5)
project(dlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c99 -Wall -Werror")
set(SOURCE_FILES dlist.c dlist.h test_dlist.c)
add_executable(test_dlist ${SOURCE_FILES})