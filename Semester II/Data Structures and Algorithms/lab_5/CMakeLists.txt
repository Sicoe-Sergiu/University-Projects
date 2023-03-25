cmake_minimum_required(VERSION 3.21)
project(lab_5_homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_5_homework
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SMMIterator.cpp
        SMMIterator.h
        SortedMultiMap.cpp
        SortedMultiMap.h)
