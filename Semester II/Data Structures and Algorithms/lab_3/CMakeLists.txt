cmake_minimum_required(VERSION 3.21)
project(lab_3_bun)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab_3_bun
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
