cmake_minimum_required(VERSION 3.21)
project(lab_1_homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_1_homework
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Matrix.cpp
        Matrix.h
        ShortTest.cpp
        ShortTest.h)
