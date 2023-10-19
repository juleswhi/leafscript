//
// Created by jules on 14/10/2023.
//

#ifndef LEAFSCRIPT_VALUE_H
#define LEAFSCRIPT_VALUE_H

#include "common.h"

typedef enum {
    VAL_BOOL,
    VAL_NULL,
    VAL_NUMBER
} ValueType;


// Holds the literal value of a number.
// Only supports double ( floating point ) nums

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
    } as;
} Value;

#define IS_BOOL(value)   ((value).type == VAL_BOOL)
#define IS_NULL(value)   ((value).type == VAL_NULL)
#define IS_NUMBER(value) ((value).type == VAL_NUMBER)

#define AS_BOOL(value)    ((value).as.boolean)
#define AS_NUMBER(value)  ((value).as.number)

#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
#define NULL_VAL          ((Value){VAL_NULL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

// Define an actual value array
// Should also have a capacity and count variable to keep track of the size
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

// Should have methods to manage memory

bool valuesEqual(Value a, Value b);
void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif
