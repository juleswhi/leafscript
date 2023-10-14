//
// Created by jules on 14/10/2023.
//

#ifndef LEAFSCRIPT_VALUE_H
#define LEAFSCRIPT_VALUE_H

#include "common.h"

// Holds the literal value of a numberalderson
// Only supports double ( floating point ) nums

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif //LEAFSCRIPT_VALUE_H
