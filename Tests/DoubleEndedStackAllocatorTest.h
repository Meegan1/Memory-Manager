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
        checkRemoveItems();
        checkFreeItems();
    }

private:
    void checkCreation() {
        // create double ended stack
        stack = new DoubleEndedStackAllocator(8);
        assert(stack->getSize() == 8); // check if the size is correct

        // allocate 3 bytes on bottom
        stack->allocBottom(3);

        // allocate 6 bytes on top (1 more than max)
        void *object = stack->allocTop(6); // should return null pointer as exceeds total size
        assert(object == nullptr); // check if null pointer

        stack->clear(); // clear stack
    }

    void checkAddItems() {
        // create object on bottom of stack
        short int *bottom = (short int *) stack->allocBottom(2);
        *bottom = 11;

        // create object on top of stack
        short int *top = (short int *) stack->allocTop(2);
        *top = 22;

        // create another object on the bottom
        short int *bottom_second = (short int *) stack->allocBottom(2);
        *bottom_second = 33;

        // check vallues are correct
        assert(*bottom == 11);
        assert(*bottom_second == 33);
        assert(*top == 22);

        // add another object on top, with invalid size (exceeds total size of stacks)
        short int *top_second = (short int *) stack->allocTop(3); // should return null pointer
        assert(top_second == nullptr); // failed to allocate memory as requested size greater than size of stack

        // retry with compatible size
        top_second = (short int *) stack->allocTop(2);
        assert(top_second != nullptr); // check isn't null
        *top_second = 44; // store value in memory address
        assert(*top_second == 44);
    }

    void checkRemoveItems() {
        // check if full
        short int *bottom_third = (short int *) stack->allocBottom(2);
        assert(bottom_third == nullptr);

        // reset bottom marker to 0 and retry
        stack->freeBottomToMarker(0);
        bottom_third = (short int *) stack->allocBottom(2);
        assert(bottom_third != nullptr);

        // get marker for top stack and allocate remaining space
        DoubleEndedStackAllocator::Marker marker = stack->getMarkerTop();
        void *top_third = stack->allocTop(2);
        assert(top_third != nullptr);

        // attempt to allocate new object to top stack
        short int *top_fourth = (short int *) stack->allocTop(2);
        assert(top_fourth == nullptr);

        // free to marker then try again
        stack->freeTopToMarker(marker);
        top_fourth = (short int *) stack->allocTop(2);
        assert(top_fourth != nullptr);
    }

    void checkFreeItems() {
        // check if full
        short int *bottom = (short int *) stack->allocBottom(2);
        assert(bottom == nullptr);

        // clear stack
        stack->clear();
        assert(stack->getMarkerBottom() == 0);
        assert(stack->getMarkerTop() == 0);

        // try adding new objects
        bottom = (short int *) stack->allocBottom(2);
        assert(bottom != nullptr);
        short int *top = (short int *) stack->allocTop(2);
        assert(top != nullptr);
    }

    DoubleEndedStackAllocator *stack;
};


#endif //ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATORTEST_H
