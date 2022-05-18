cmake_minimum_required(VERSION 3.20)
project(DA_First_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(DA_First_Project
        main.cpp
        src/courier.cpp
        src/courier.h
        src/data.cpp
        src/data.h
        src/exceptions.h
        src/input.cpp
        src/input.h
        ../DA_Project2/src/menu.cpp
        ../DA_Project2/src/menu.h
        src/package.cpp
        src/package.h
        src/platform.cpp
        src/platform.h
        src/utils.cpp
        src/utils.h
        src/van.cpp
        src/van.h)
