//
// Created by Jake Meegan on 03/11/2019.
//

#ifndef ASSIGNMENT_1_SMARTPOINTERTEST_H
#define ASSIGNMENT_1_SMARTPOINTERTEST_H


#include "../Allocators/SmartPointer.h"
#include "../Allocators/PoolAllocator.h"

class SmartPointerTest {
public:
    SmartPointerTest() {
        init();
    }

    void init() {
        checkCreation();
    }

private:
    void checkCreation() {
        // create smart pointer for pool
        SmartPointer<PoolAllocator> pool(new PoolAllocator(10, 5));
        void *memory = pool->alloc();
        assert(memory != nullptr); // check pool is operating correctly
    }
};

#endif //ASSIGNMENT_1_SMARTPOINTERTEST_H
