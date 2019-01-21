cmake_minimum_required(VERSION 3.5)
project(mystring)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c99 -Wall -Werror")
set(SOURCE_FILES mystring.c test_mystring.c mystring.h)
add_executable(test_mystring ${SOURCE_FILES})