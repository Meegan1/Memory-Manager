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
        checkStack();
        checkDoubleEndedStack();
        checkPool();
    }

    void checkStack() {
        MemoryManager<StackAllocator> stack(23);
        float *test = stack.add(float(54));
    }

    void checkDoubleEndedStack() {
        MemoryManager<DoubleEndedStackAllocator> doubleStack(23);
        float *testBottom = doubleStack.add(float(100));
        float *testTop = doubleStack.add(float(100), true);
    }

    void checkPool() {
        MemoryManager<PoolAllocator, long> pool(5);
        long *test = pool.add(long(25));
        long *test2 = (long *) pool.add(99);

        assert(*test == 25);
        assert(*test2 == 99);

        pool.remove(test);
        long *test3 = pool.add(long(55));

        assert(test = test3);

        MemoryManager<PoolAllocator> t(23, 44);
    }
};


#endif //ASSIGNMENT_1_MEMORYMANAGERTEST_H
