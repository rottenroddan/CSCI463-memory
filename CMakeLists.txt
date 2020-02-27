cmake_minimum_required(VERSION 3.10)
project(memory)

set(CMAKE_CXX_STANDARD 17)

add_executable(memory main.cpp hex.h hex.cpp memory.h memory.cpp)