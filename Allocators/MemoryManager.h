//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_MEMORYMANAGER_H
#define ASSIGNMENT_1_MEMORYMANAGER_H


#include "PoolAllocator.h"

template <class T>  class MemoryManager {
private:
    T* allocator;

public:
    explicit MemoryManager(std::size_t size): allocator(new T(size)) {}

    void add(std::size_t size) {
        allocator->alloc(size);
    }
};

template <> class MemoryManager<PoolAllocator> {
private:
    PoolAllocator* allocator;
public:
    explicit MemoryManager(std::size_t blockSize, std::size_t totalBlocks): allocator(new PoolAllocator(blockSize, totalBlocks)) {}
};

#endif //ASSIGNMENT_1_MEMORYMANAGER_H
