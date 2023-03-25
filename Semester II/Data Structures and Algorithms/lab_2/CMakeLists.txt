cmake_minimum_required(VERSION 3.21)
project(lab_2_homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_2_homework
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
