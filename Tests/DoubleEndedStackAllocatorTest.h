//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATORTEST_H
#define ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATORTEST_H


#include "../Allocators/DoubleEndedStackAllocator.h"

class DoubleEndedStackAllocatorTest {
public:
    DoubleEndedStackAllocatorTest() {
        init();
    }

    void init() {
        checkCreation();
        checkAddItems();
    }

private:
    void checkCreation() {
        stack = new DoubleEndedStackAllocator(8);
        assert(stack->getSize() == 8);
    }

    void checkAddItems() {
        short int *first_bottom = (short int *) stack->allocBottom(2);
        *first_bottom = 11;

        short int *first_top = (short int *) stack->allocTop(2);
        *first_top = 22;

        short int *second_bottom = (short int *) stack->allocBottom(2);
        *second_bottom = 33;

        assert(*first_bottom == 11);
        assert(*second_bottom == 33);
        assert(*first_top == 22);

        short int *second_top = (short int *) stack->allocTop(3);
        assert(second_top == nullptr); // failed to allocate memory as requested size greater than size of stack

        second_top = (short int *) stack->allocTop(2); // retry with compatible size
        assert(second_top != nullptr);
        *second_top = 44;
        assert(*second_top == 44);
    }

    DoubleEndedStackAllocator *stack;
};


#endif //ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATORTEST_H
