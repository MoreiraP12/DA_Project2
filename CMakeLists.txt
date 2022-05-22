cmake_minimum_required(VERSION 3.20)
project(DA_First_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA_First_Project
        main.cpp
        src/data.cpp
        src/data.h
        src/graph.cpp
        src/graph.h
        src/input.cpp
        src/input.h
        src/menu.cpp
        src/menu.h
        src/utils.cpp
        src/utils.h src/exceptions.cpp src/exceptions.h)
