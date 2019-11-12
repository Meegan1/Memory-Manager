//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_SMARTPOINTER_H
#define ASSIGNMENT_1_SMARTPOINTER_H

#include "ReferenceCount.h"

/*
 * Smart Pointer
 */
template<typename T>
class SmartPointer {
public:
    SmartPointer(){ // constructor
        count = new ReferenceCount();
        count->add(); // add to reference count
    }

    explicit SmartPointer(T *pointer) : pointer(pointer) { // constructor with object passed to it
        count = new ReferenceCount();
        count->add(); // add to reference count
    }

    SmartPointer(const SmartPointer<T> &other) : pointer(other.pointer), count(other.count) { //  copy constructor
        count->add(); // add to reference count
    };

    ~SmartPointer(){ // destructor
        if (count->release() == 0) { // if reference counter is 0, delete data and counter
            delete pointer;
            delete count;
        }
    };

    // operator overloads
    T &operator*() {
        return *pointer;
    };

    T *operator->() {
        return pointer;
    };

    SmartPointer<T> &operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            if (count->release() == 0) { // if reference counter is 0, delete data and counter
                delete pointer;
                delete count;
            }

            // copy attributes from other SmartPointer
            pointer = other.pointer;
            count = other.count;
            count->add(); // add to reference count
        }
        return *this;
    };

private:
    T *pointer; // pointer to data
    ReferenceCount *count; // reference counter object
};


#endif //ASSIGNMENT_1_SMARTPOINTER_H
