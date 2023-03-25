cmake_minimum_required(VERSION 3.21)
project(lab_4_homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_4_homework
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Set.cpp
        Set.h
        SetIterator.cpp
        SetIterator.h
        ShortTest.cpp
        ShortTest.h)
