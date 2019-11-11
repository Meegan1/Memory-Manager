//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_ALLOCATOR_H
#define ASSIGNMENT_1_ALLOCATOR_H

#include <cstdlib>

class Allocator {
public:
    Allocator(std::size_t size_bytes) {
        total_size = size_bytes;
    }

    std::size_t getSize() {
        return total_size;
    }

private:
    std::size_t total_size;
};


#endif //ASSIGNMENT_1_ALLOCATOR_H
