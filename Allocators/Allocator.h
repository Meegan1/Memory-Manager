//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_ALLOCATOR_H
#define ASSIGNMENT_1_ALLOCATOR_H

#include <cstdlib>

/*
 * Super Class for all Allocators
 */
class Allocator {
public:
    // constructor
    explicit Allocator(std::size_t size_bytes) {
        total_size = size_bytes;
    }

    // return total size
    std::size_t getSize() {
        return total_size;
    }

private:
    std::size_t total_size; // stores the total size of the memory
};


#endif //ASSIGNMENT_1_ALLOCATOR_H
