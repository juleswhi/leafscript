//
// Created by elliot alderson on 14/10/2023.
//

#ifndef LEAFSCRIPT_MEMORY_H
#define LEAFSCRIPT_MEMORY_H

#include "common.h"
#include "object.h"

#define ALLOCATE(type, count) \
    (type*)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer)   reallocate(pointer, sizeof(type), 0);
// if less than a byte, set to that or else just double it
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

void* reallocate(void* pointer, size_t oldSize, size_t newSize);
void freeObjects();

#endif //LEAFSCRIPT_MEMORY_H
