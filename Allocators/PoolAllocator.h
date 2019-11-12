//
// Created by Jake Meegan on 03/11/2019.
//

#ifndef ASSIGNMENT_1_POOLALLOCATOR_H
#define ASSIGNMENT_1_POOLALLOCATOR_H


#include "Allocator.h"

/*
 *
 */
class PoolAllocator : public Allocator {
public:
    PoolAllocator(std::size_t blockSize, std::size_t totalBlocks); // allocates memory size of blockSize * totalBlocks
    void *alloc(); // allocate a block
    void dealloc(void *block); // deallocate a block
    void clear();

private:
    std::size_t blockSize; // stores block size
    std::size_t totalBlocks; // stores total number of possible blocks
    void *pool; // pointer to pool
    void **head; // pointer to current head of pool
};


#endif //ASSIGNMENT_1_POOLALLOCATOR_H
