cmake_minimum_required(VERSION 3.6)
project(task_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Circle.cpp Circle.h)
add_executable(task_test ${SOURCE_FILES})