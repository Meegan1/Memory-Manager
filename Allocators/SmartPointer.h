//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_SMARTPOINTER_H
#define ASSIGNMENT_1_SMARTPOINTER_H

#include "ReferenceCount.h"

template<typename T>
class SmartPointer {
public:
    SmartPointer() : pointer(), count() {
        count = new ReferenceCount();
        count->add();
    }

    SmartPointer(T *pointer) : pointer(pointer), count() {
        count = new ReferenceCount();
        count->add();
    }

    SmartPointer(const SmartPointer<T> &other) : pointer(other.pointer), count(other.count) {
        count->add();
    }

    ~SmartPointer() {
        if (count->release() == 0) {
            delete pointer;
            delete count;
        }
    }

    T &operator*() {
        return *pointer;
    }

    T *operator->() {
        return pointer;
    }

    SmartPointer<T> &operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            if (count->release() == 0) {
                delete pointer;
                delete count;
            }

            pointer = other.pointer;
            count = other.count;
            count->add();
        }
        return *this;
    }

private:
    T *pointer;
    ReferenceCount *count;
};


#endif //ASSIGNMENT_1_SMARTPOINTER_H
