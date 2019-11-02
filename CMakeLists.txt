cmake_minimum_required(VERSION 3.15)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_1 main.cpp StackAllocator.cpp StackAllocator.h Allocator.h DoubleEndedStackAllocator.cpp DoubleEndedStackAllocator.h)