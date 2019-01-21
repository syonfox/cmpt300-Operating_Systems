cmake_minimum_required(VERSION 3.5)
project(mystring)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c99 -Wall -Werror")
set(SOURCE_FILES list.c list.h test_list.c list.h list.c test_list.c)
add_executable(test_list ${SOURCE_FILES})