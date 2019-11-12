//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H
#define ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H


#include "Allocator.h"

/*
 * Double Ended Stack Allocator
 */
class DoubleEndedStackAllocator : public Allocator {
public:
    typedef std::size_t Marker; // define marker type

    explicit DoubleEndedStackAllocator(std::size_t stackSize_bytes); // constructor (allocates total size)
    void *allocBottom(std::size_t size_bytes); // allocate to bottom stack
    void *allocTop(std::size_t size_bytes); // allocate to top stack
    Marker getMarkerBottom(); // get current position of bottom stack
    Marker getMarkerTop(); // get current position of top stack
    void freeBottomToMarker(Marker marker); // free bottom stack to position of given marker
    void freeTopToMarker(Marker marker); // free top stack to position of given marker
    void clear(); // reset position of both stacks in order to clear them

private:
    void *stack_ptr; // pointer to bottom stack
    void *stack_ptr_end; // pointer to top stack
    Marker offset_bottom; // current position of bottom stack
    Marker offset_top; // current position of top stack
};


#endif //ASSIGNMENT_1_DOUBLEENDEDSTACKALLOCATOR_H
