#include "Allocators/StackAllocator.h"
#include "Tests/StackAllocatorTest.h"
#include "Tests/DoubleEndedStackAllocatorTest.h"
#include "Tests/PoolAllocatorTest.h"
#include "Tests/SmartPointerTest.h"
#include "Tests/MemoryManagerTest.h"

int main() {
    StackAllocatorTest();
    DoubleEndedStackAllocatorTest();
    PoolAllocatorTest();
    SmartPointerTest();
    MemoryManagerTest();
    return 0;
}