//
// Created by elliot alderson on 14/10/2023.
//

#ifndef LEAFSCRIPT_CHUNK_H
#define LEAFSCRIPT_CHUNK_H

#include "common.h"

typedef enum {
    OP_RETURN,
} OpCode;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte);

#endif //LEAFSCRIPT_CHUNK_H
