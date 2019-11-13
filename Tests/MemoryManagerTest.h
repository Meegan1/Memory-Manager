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
        // create stack
        MemoryManager<StackAllocator> stack(23);

        // get marker for stack
        StackAllocator::Marker marker = stack.getMarker();

        // assign value
        float *test = stack.add(float(54));
        assert(*test == 54);

        // revert back to marker
        stack.freeToMarker(marker);

        // add new object at marker
        float *test2 = stack.add(float(33));

        // verify new object's memory address is same as the first
        assert(test2 == test);

        stack.clear();

        // add random objects to trigger 25% memory remaining message
        stack.add(22);
        stack.add(22);
        stack.add(22);
        stack.add(22);
        stack.add(22);
        stack.add(22);
        stack.add(22);
        stack.add(22);
    }

    void checkDoubleEndedStack() {
        // create double ended stack allocator
        MemoryManager<DoubleEndedStackAllocator> doubleStack(23);

        // get marker for top and bottom
        DoubleEndedStackAllocator::Marker markerBottom = doubleStack.getMarker();
        DoubleEndedStackAllocator::Marker markerTop = doubleStack.getMarker(true);

        // add object to bottom
        float *testBottom = doubleStack.add(float(100));
        assert(*testBottom == 100);

        // add object to top
        float *testTop = doubleStack.add(float(50), true);
        assert(*testTop == 50);


        // reset top and bottom stacks to the markers
        doubleStack.freeToMarker(markerBottom);
        doubleStack.freeToMarker(markerTop, true);

        // add object to bottom
        float *testBottom2 = doubleStack.add(float(200));
        assert(*testBottom2 == 200);

        // add object to top
        float *testTop2 = doubleStack.add(float(25), true);
        assert(*testTop2 == 25);

        // verify that new objects are in the position of the previous objects
        assert(testBottom2 == testBottom && testTop2 == testTop);
    }

    void checkPool() {
        // create pool to store 5 long's
        MemoryManager<PoolAllocator, long> pool(5);

        // add longs
        long *test = pool.add(long(25));
        long *test2 = pool.add(99);

        // verify values
        assert(*test == 25);
        assert(*test2 == 99);

        // remove long
        pool.remove(test);

        // add long in it's place
        long *test3 = pool.add(long(55));

        // verify that memory addresses are the same
        assert(test = test3);

        // create pool with no specified type
        MemoryManager<PoolAllocator> pool2(23, 44);
    }
};


#endif //ASSIGNMENT_1_MEMORYMANAGERTEST_H
