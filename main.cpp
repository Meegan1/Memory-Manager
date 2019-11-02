#include <iostream>
#include "StackAllocator.h"

int main() {
    StackAllocator stack(0, 4);

    StackAllocator::Marker marker = stack.getMarker();

    short int *first = (short int *)stack.alloc(2);
    *first = 54;
    short int *second = (short int *)stack.alloc(2);
    *second = 99;
    std::cout << *first << *second << std::endl;

    *first = 23;

    std::cout << *first << *second << std::endl;

    stack.freeToMarker(marker);

    short int *third = (short int *)stack.alloc(2);
    *third = 13;
    std::cout << *first << *second << std::endl;

    std::cout << sizeof(stack) << std::endl;
    return 0;
}