//
// Created by elliot alderson on 14/10/2023.
//

#ifndef LEAFSCRIPT_MEMORY_H
#define LEAFSCRIPT_MEMORY_H

#include "common.h"

// if less than a byte, set to that or else just double it
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type) * (oldCount), \
        sizeof(type) * (newCount))

void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif //LEAFSCRIPT_MEMORY_H
