cmake_minimum_required(VERSION 3.5)
project(Quicksort_Analysis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES quicksort-allex.c)
add_executable(Quicksort_Analysis ${SOURCE_FILES})