cmake_minimum_required(VERSION 3.14)
project(RegExToDFA)

set(CMAKE_CXX_STANDARD 14)

add_executable(RegExToDFA main.cpp Tree.cpp Tree.h Node.cpp Node.h)