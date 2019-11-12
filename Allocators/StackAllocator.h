//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_STACKALLOCATOR_H
#define ASSIGNMENT_1_STACKALLOCATOR_H


#include "Allocator.h"

/*
 * Stack Allocator
 */
class StackAllocator : public Allocator {
public:
    typedef std::size_t Marker; // define marker type

    explicit StackAllocator(std::size_t stackSize_bytes); // constructor (allocates stack size)
    void *alloc(std::size_t size_bytes); // allocates to stack
    Marker getMarker(); // get current position of stack
    void freeToMarker(Marker marker); // free to position of given marker
    void clear(); // clear stack (resets position)

private:
    void *stack_ptr; // pointer to stack
    Marker offset; // current position of stack
};


#endif //ASSIGNMENT_1_STACKALLOCATOR_H
