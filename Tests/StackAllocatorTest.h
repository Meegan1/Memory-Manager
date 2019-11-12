//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_STACKALLOCATORTEST_H
#define ASSIGNMENT_1_STACKALLOCATORTEST_H


#include <iostream>
#include "../Allocators/StackAllocator.h"

class StackAllocatorTest {
public:
    StackAllocatorTest() {
        init();
    }

    void init() {
        checkCreation();
        checkAddItems();
    }

private:
    void checkCreation() {
        stack = new StackAllocator(20);
        assert(stack->getSize() == 20);
    }

    void checkAddItems() {
        StackAllocator::Marker firstMarker = stack->getMarker();

        short int *first = (short int *) stack->alloc(2);
        *first = 54;
        short int *second = (short int *) stack->alloc(2);
        *second = 99;

        assert(*first == 54);
        assert(*second == 99);

        *first = 23;
        assert(*first == 23);

        stack->freeToMarker(firstMarker);
        short int *third = (short int *) stack->alloc(2);
        *third = 13;
        assert(*third == 13);
    }

    StackAllocator *stack;
};


#endif //ASSIGNMENT_1_STACKALLOCATORTEST_H
