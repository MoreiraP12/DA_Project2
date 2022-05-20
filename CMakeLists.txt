cmake_minimum_required(VERSION 3.20)
project(DA_First_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA_First_Project
        main.cpp
        src/graph.cpp src/graph.h)
