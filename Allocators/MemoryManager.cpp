//
// Created by Jake Meegan on 12/11/2019.
//



#include "MemoryManager.h"

MemoryManager<StackAllocator>::MemoryManager(std::size_t size) : allocator(new StackAllocator(size)) {}
