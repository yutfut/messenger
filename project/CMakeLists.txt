cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(project
        include/data_base.h
        src/data_base.cpp)
