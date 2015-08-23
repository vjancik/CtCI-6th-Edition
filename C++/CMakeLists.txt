cmake_minimum_required (VERSION 2.6)
project (CtCI6Edition)

set(CMAKE_CXX_COMPILER "g++")
list(APPEND CMAKE_CXX_FLAGS "-g -std=c++11 -Wall")

add_subdirectory(lib)
add_subdirectory(src)
