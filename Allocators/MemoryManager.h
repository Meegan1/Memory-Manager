//
// Created by Jake Meegan on 11/11/2019.
//

#ifndef ASSIGNMENT_1_MEMORYMANAGER_H
#define ASSIGNMENT_1_MEMORYMANAGER_H


#include <cassert>
#include "PoolAllocator.h"
#include "StackAllocator.h"
#include "DoubleEndedStackAllocator.h"

template<class T, typename U = void>
class MemoryManager;

template<>
class MemoryManager<StackAllocator> {
public:
    explicit MemoryManager(std::size_t size) : allocator(new StackAllocator(size)) {}

    void *add(std::size_t size) {
        return allocator->alloc(size);
    }

    template<typename U>
    U *add(U object) {
        U *stored = (U *) allocator->alloc(sizeof(U));
        *stored = object;
        return stored;
    }

    StackAllocator::Marker getMarker() {
        return allocator->getMarker();
    }

    void freeToMarker(StackAllocator::Marker marker) {
        allocator->freeToMarker(marker);
    }

    void clear() {
        allocator->clear();
    }

private:
    StackAllocator *allocator;
};

template<>
class MemoryManager<DoubleEndedStackAllocator> {
public:
    explicit MemoryManager(std::size_t size) : allocator(new DoubleEndedStackAllocator(size)) {}

    void *add(std::size_t size, bool isTop = false) {
        if (isTop)
            return allocator->allocTop(size);
        else
            return allocator->allocBottom(size);
    }

    template<typename U>
    U *add(U object, bool isTop = false) {
        U *stored;

        if (isTop)
            stored = (U *) allocator->allocTop(sizeof(U));
        else
            stored = (U *) allocator->allocBottom(sizeof(U));

        *stored = object;
        return stored;
    }

    StackAllocator::Marker getMarker(bool isTop = false) {
        return (isTop) ? allocator->getMarkerTop() : allocator->getMarkerBottom();
    }

    void freeToMarker(StackAllocator::Marker marker, bool isTop = false) {
        (isTop) ? allocator->freeTopToMarker(marker) : allocator->freeBottomToMarker(marker);
    }

    void clear() {
        allocator->clear();
    }

private:
    DoubleEndedStackAllocator *allocator;
};

template<>
class MemoryManager<PoolAllocator> {
public:
    explicit MemoryManager(std::size_t blockSize, std::size_t totalBlocks) : allocator(
            new PoolAllocator(blockSize, totalBlocks)) {
        assert(blockSize >= sizeof(void *));
    }

    void *add() {
        return allocator->alloc();
    }

    void remove(void *object) {
        allocator->dealloc(object);
    }

private:
    PoolAllocator *allocator;
};

template<typename U>
class MemoryManager<PoolAllocator, U> {
public:
    explicit MemoryManager(std::size_t totalBlocks) : allocator(new PoolAllocator(sizeof(U), totalBlocks)) {
        assert(sizeof(U) >= sizeof(void *));
    }

    U *add(U object) {
        U *stored = (U *) allocator->alloc();
        *stored = object;
        return (U *) stored;
    }

    void remove(U *object) {
        allocator->dealloc(object);
    }

private:
    PoolAllocator *allocator;
};

#endif //ASSIGNMENT_1_MEMORYMANAGER_H
