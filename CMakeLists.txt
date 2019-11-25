cmake_minimum_required(VERSION 3.15)
project(BinomialHeap)

set(CMAKE_CXX_STANDARD 14)

add_executable(BinomialHeap main.cpp
        src/services/TimerService.h
        src/BinomialHeap.cpp src/BinomialHeap.h src/services/FillHeapService.h)