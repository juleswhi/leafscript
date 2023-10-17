//
// Created by elliot alderson on 14/10/2023.
//

#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

// Set values to 0 / NULL
// Also should actually set up the array to the constants

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->lines = NULL;
    chunk->code = NULL;
    // Init the value array constants as well
    initValueArray(&chunk->constants);

}

// Get rid of that memory fr

void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}



// Resize the old array and then do some pointer arithmetic to update the size of the chunk array
void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if(chunk->capacity < chunk->count + 1)  {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines = GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}


// Add a new constant to the arr
int addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}