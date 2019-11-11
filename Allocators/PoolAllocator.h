//
// Created by Jake Meegan on 03/11/2019.
//

#ifndef ASSIGNMENT_1_POOLALLOCATOR_H
#define ASSIGNMENT_1_POOLALLOCATOR_H


#include "Allocator.h"

class PoolAllocator: public Allocator {
public:
    PoolAllocator(std::size_t blockSize, std::size_t totalBlocks);

    void *alloc();

    void dealloc(void *block);

private:
    std::size_t blockSize;
    std::size_t totalBlocks;
    void *pool;

    void **head;
};


#endif //ASSIGNMENT_1_POOLALLOCATOR_H
