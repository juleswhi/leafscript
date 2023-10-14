//
// Created by jules on 14/10/2023.
//

#include <stdio.h>

#include "debug.h"

int SimpleInstruction(const char *string, int offset);

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for(int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk* chunk, int offset) {
    printf("%04d ", offset);

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        case OP_RETURN:
            return SimpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

int SimpleInstruction(const char *string, int offset) {
    printf("%s\n", string);
    return offset + 1;
}
