cmake_minimum_required(VERSION 3.6)
project(OverloadingOperators)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    OverloadingOperators/testDate.cpp
    OverloadingOperators/upDate.cpp
    OverloadingOperators/upDate.h)

add_executable(OverloadingOperators ${SOURCE_FILES})