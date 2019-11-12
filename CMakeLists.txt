cmake_minimum_required(VERSION 3.15)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_1 main.cpp Allocators/StackAllocator.cpp Allocators/StackAllocator.h Allocators/Allocator.h Allocators/DoubleEndedStackAllocator.cpp Allocators/DoubleEndedStackAllocator.h Tests/StackAllocatorTest.h Tests/DoubleEndedStackAllocatorTest.h Allocators/PoolAllocator.cpp Allocators/PoolAllocator.h Tests/PoolAllocatorTest.h Allocators/SmartPointer.h Tests/SmartPointerTest.h Allocators/ReferenceCount.h Allocators/MemoryManager.h Tests/MemoryManagerTest.h)