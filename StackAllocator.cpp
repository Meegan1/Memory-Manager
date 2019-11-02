//
// Created by Jake Meegan on 02/11/2019.
//

#include <cstdlib>
#include <stdexcept>
#include "StackAllocator.h"

StackAllocator::StackAllocator(std::size_t sizeBytes, unsigned int stackSize_bytes) : Allocator(sizeBytes) {
    this->stack_ptr = malloc(stackSize_bytes);
    this->offset = 0;
}

void *StackAllocator::alloc(unsigned int size_bytes) {
    if(this->offset + size_bytes > this->total_size)
        throw std::range_error("Requested size of allocation exceeds stack size limit");

    std::size_t address = (std::size_t) this->stack_ptr + this->offset;

    this->offset += size_bytes;
    return (void*) address;
}

StackAllocator::Marker StackAllocator::getMarker() {
    return this->offset;
}

void StackAllocator::freeToMarker(StackAllocator::Marker marker) {
    free(this->stack_ptr);
    this->offset = marker;
}

void StackAllocator::clear() {
    this->offset = 0;
}