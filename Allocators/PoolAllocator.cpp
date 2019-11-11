//
// Created by Jake Meegan on 03/11/2019.
//

#include "PoolAllocator.h"

PoolAllocator::PoolAllocator(std::size_t blockSize, std::size_t totalBlocks)
        :
        Allocator(blockSize * totalBlocks),
        blockSize(blockSize),
        totalBlocks(totalBlocks) {

    pool = malloc(blockSize * totalBlocks);
    head = &pool;

    for (std::size_t block_count = 0; block_count < totalBlocks; block_count++) {
        void *curr_address = (void *) ((std::size_t) pool + (block_count * blockSize));
        void **curr_memory = (void **) curr_address;

        if (block_count == totalBlocks - 1) {
            *curr_memory = nullptr;
            continue;
        }

        void *next_address = (void *) ((std::size_t) curr_address + blockSize);
        *curr_memory = next_address;
    }
}

void *PoolAllocator::alloc() {
    void *address = *head; // store free address in temp address
    head = (void **) *head; // store next free address in head
    return address; // return address
}

void PoolAllocator::dealloc(void *block) {
    if (block == nullptr)
        return;

    if (head == nullptr) {
        head = (void **) block;
        *head = nullptr;
    } else {
        void **returned_block = head;
        head = (void **) block;
        *head = (void *) returned_block;
    }
}