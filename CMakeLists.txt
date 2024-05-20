cmake_minimum_required(VERSION 3.28)
project(Final_project)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Final_project main.cpp
        Game.cpp
        Game.h)
