//
// Created by Jake Meegan on 02/11/2019.
//

#include "DoubleEndedStackAllocator.h"

DoubleEndedStackAllocator::DoubleEndedStackAllocator(std::size_t stackSize_bytes) : Allocator(stackSize_bytes) {
    stack_ptr = malloc(stackSize_bytes);
    stack_ptr_end = (void *) ((std::size_t *) stack_ptr + stackSize_bytes);
    offset_bottom = 0;
    offset_top = 0;
}

void *DoubleEndedStackAllocator::allocBottom(std::size_t size_bytes) {
    if ((offset_bottom + size_bytes + offset_top) > getSize())
        return nullptr;

    std::size_t address = (std::size_t) stack_ptr + offset_bottom;
    offset_bottom += size_bytes;

    return (void *) address;
}

void *DoubleEndedStackAllocator::allocTop(std::size_t size_bytes) {
    if ((offset_bottom + size_bytes + offset_top) > getSize())
        return nullptr;

    offset_top += size_bytes;
    std::size_t address = (std::size_t) stack_ptr_end - offset_top;

    return (void *) address;
}

DoubleEndedStackAllocator::Marker DoubleEndedStackAllocator::getMarkerBottom() {
    return offset_bottom;
}

DoubleEndedStackAllocator::Marker DoubleEndedStackAllocator::getMarkerTop() {
    return offset_top;
}

void DoubleEndedStackAllocator::freeBottomToMarker(DoubleEndedStackAllocator::Marker marker) {
    if(marker < offset_bottom) // only free if less than current offset
        offset_bottom = marker;
}

void DoubleEndedStackAllocator::freeTopToMarker(DoubleEndedStackAllocator::Marker marker) {
    if(marker < offset_top) // only free if less than current offset
        offset_top = marker;
}

void DoubleEndedStackAllocator::clear() {
    offset_bottom = 0;
    offset_top = 0;
}

