//
// Created by Jake Meegan on 02/11/2019.
//

#ifndef ASSIGNMENT_1_ALLOCATOR_H
#define ASSIGNMENT_1_ALLOCATOR_H


class Allocator {
public:
    explicit Allocator(const std::size_t size_bytes) {
        this->total_size = size_bytes;
    }

    virtual void* alloc() = 0;

    virtual void clear() = 0;

protected:
    std::size_t total_size;
};


#endif //ASSIGNMENT_1_ALLOCATOR_H
