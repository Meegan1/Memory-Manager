//
// Created by Jake Meegan on 02/11/2019.
//

#include "StackAllocator.h"

StackAllocator::StackAllocator(std::size_t stackSize_bytes) : Allocator(stackSize_bytes) {
    stack_ptr = malloc(stackSize_bytes);
    offset = 0;
}

void *StackAllocator::alloc(std::size_t size_bytes) {
    if (offset + size_bytes > this->getSize())
        return nullptr;

    std::size_t address = (std::size_t) stack_ptr + offset;
    offset += size_bytes;

    return (void *) address;
}

StackAllocator::Marker StackAllocator::getMarker() {
    return offset;
}

void StackAllocator::freeToMarker(StackAllocator::Marker marker) {
    offset = marker;
}

void StackAllocator::clear() {
    offset = 0;
}