//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_MEMORYMANAGERTEST_H
#define ASSIGNMENT_1_MEMORYMANAGERTEST_H


#include "../Allocators/StackAllocator.h"
#include "../Allocators/MemoryManager.h"

class MemoryManagerTest {
public:
    MemoryManagerTest() {
        init();
    }

    void init() {
        checkCreation();
    }

private:
    void checkCreation() {
        MemoryManager<StackAllocator> pool(23);
    }
};


#endif //ASSIGNMENT_1_MEMORYMANAGERTEST_H
