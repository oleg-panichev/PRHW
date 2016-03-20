cmake_minimum_required(VERSION 3.3)
project(IntImage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp IntImage.cpp IntImage.h)
add_executable(IntImage ${SOURCE_FILES})