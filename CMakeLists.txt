cmake_minimum_required(VERSION 3.6)
project(FlowEngine)

# Use C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(FlowEngine src/main.cpp)
