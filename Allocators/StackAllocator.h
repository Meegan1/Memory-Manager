//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_STACKALLOCATOR_H
#define ASSIGNMENT_1_STACKALLOCATOR_H


#include "Allocator.h"

class StackAllocator : public Allocator {
public:
    typedef std::size_t Marker;

    explicit StackAllocator(std::size_t stackSize_bytes);

    void* alloc(std::size_t size_bytes);

    Marker getMarker();

    void freeToMarker(Marker marker);

    void clear();

private:
    void* stack_ptr;
    Marker offset;
};


#endif //ASSIGNMENT_1_STACKALLOCATOR_H
