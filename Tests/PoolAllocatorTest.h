//
// Created by Jake Meegan on 03/11/2019.
//

#ifndef ASSIGNMENT_1_POOLALLOCATORTEST_H
#define ASSIGNMENT_1_POOLALLOCATORTEST_H


#include "../Allocators/PoolAllocator.h"

class PoolAllocatorTest {
public:
    PoolAllocatorTest() {
        init();
    }

    void init() {
        checkCreation();
    }

private:
    void checkCreation() {
        pool = new PoolAllocator(8, 10);
        assert(pool->getSize() == 80);

        void *firstElement = pool->alloc();
        pool->alloc();

        pool->dealloc(firstElement);
    }

    PoolAllocator *pool;
};


#endif //ASSIGNMENT_1_POOLALLOCATORTEST_H
