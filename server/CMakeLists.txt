
cmake_minimum_required(VERSION 3.17)
project(server)

set(CMAKE_CXX_STANDARD 17)

add_executable(server source/main.cpp source/server.cpp)