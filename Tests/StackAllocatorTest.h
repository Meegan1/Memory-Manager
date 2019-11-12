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
        checkRemoveItems();
        checkClearItems();
    }

private:
    void checkCreation() {
        stack = new StackAllocator(20);
        assert(stack->getSize() == 20); // check size is correct

        // fill stack
        void *object = stack->alloc(20);
        assert(object != nullptr);

        // attempt to create object
        void *null_object = stack->alloc(1);
        assert(null_object == nullptr);

        // clear stack
        stack->clear();
    }

    void checkAddItems() {
        // add objects to stack
        short int *first = (short int *) stack->alloc(2);
        short int *second = (short int *) stack->alloc(2);

        // check pointers are valid
        assert(first != nullptr);
        assert(second != nullptr);

        // set values to variables
        *first = 54;
        *second = 99;

        // check values are stored
        assert(*first == 54);
        assert(*second == 99);

        // clear stack
        stack->clear();
    }

    void checkRemoveItems() {
        // store marker
        StackAllocator::Marker firstMarker = stack->getMarker();

        // add two objects to stack
        short int *first = (short int *) stack->alloc(2);
        short int *second = (short int *) stack->alloc(2);

        // set values of objects
        *first = 54;
        *second = 99;

        // check values are set
        assert(*first == 54);
        assert(*second == 99);

        // set value of first and check has changed
        *first = 23;
        assert(*first == 23);

        // free stack to marker
        stack->freeToMarker(firstMarker);

        // create new object in stack, should point to same address as first object
        short int *third = (short int *) stack->alloc(2);

        // set value of first object
        *third = 13;
        assert(*third == 13);
        assert(*first == 13); // check if pointer to first object == third
    }

    void checkClearItems() {
        // clear stack
        stack->clear();

        // check stack size
        assert(stack->getMarker() == 0);

        // fill stack
        stack->alloc(20);

        // add object and check if nullptr (because of max size)
        void *object = stack->alloc(1);
        assert(object == nullptr);
    }

    StackAllocator *stack;
};


#endif //ASSIGNMENT_1_STACKALLOCATORTEST_H
