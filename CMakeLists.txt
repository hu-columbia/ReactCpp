cmake_minimum_required(VERSION 3.21)
project(ReactCpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/React)
include_directories(src/ReactCurses)
include_directories(src/ReactQt)

add_subdirectory(src)
add_subdirectory(examples)
