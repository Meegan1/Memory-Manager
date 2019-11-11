//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H
#define ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H


#include "Allocator.h"

class DoubleEndedStackAllocator : public Allocator {
public:
    typedef std::size_t Marker;

    explicit DoubleEndedStackAllocator(std::size_t stackSize_bytes);

    void* allocBottom(std::size_t size_bytes);
    void* allocTop(std::size_t size_bytes);

    Marker getMarkerBottom();
    Marker getMarkerTop();

    void freeBottomToMarker(Marker marker);
    void freeTopToMarker(Marker marker);

    void clear();

private:
    void* stack_ptr;
    void* stack_ptr_end;
    Marker offset_bottom;
    Marker offset_top;
};


#endif //ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H
