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
        checkAddItems();
        checkRemoveItems();
        checkClearItems();
    }

private:
    void checkCreation() {
        // create pool to store longs (max 3)
        pool = new PoolAllocator(sizeof(long), 3);

        // check size of pool == size of long * 3
        assert(pool->getSize() == (sizeof(long) * 3));
    }

    void checkAddItems() {
        // allocate first block
        long *firstBlock = (long *) pool->alloc();
        assert(firstBlock != nullptr); // check isn't null

        // set value to first block
        *firstBlock = 100;
        assert(*firstBlock == 100);

        // create two more blocks to fill pool
        void* not_null = pool->alloc();
        void* also_not_null = pool->alloc();

        // create another block
        void *null_object = pool->alloc();

        assert(not_null != nullptr && also_not_null != nullptr); // check blocks are valid
        assert(null_object == nullptr); // check additional block doesn't fit

        // clear pool
        pool->clear();
    }

    void checkRemoveItems() {
        // allocate second block
        long *secondBlock = (long *) pool->alloc();
        assert(secondBlock != nullptr);

        // remove second block
        pool->dealloc(secondBlock);

        // allocate another block (should be in position of previously deallocated block)
        long *thirdBlock = (long *) pool->alloc();
        assert(thirdBlock == secondBlock); // check memory addresses are the same
    }

    void checkClearItems() {
        // allocate a block
        long *block = (long *) pool->alloc();
        assert(block != nullptr);

        // set value of block
        *block = 99;
        assert(*block == 99);

        // clear pool
        pool->clear();

        // check that value has been cleared
        assert(*block != 99);
    }

    PoolAllocator *pool;
};


#endif //ASSIGNMENT_1_POOLALLOCATORTEST_H
