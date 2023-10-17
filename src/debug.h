//
// Created by jules on 14/10/2023.
//

#ifndef LEAFSCRIPT_DEBUG_H
#define LEAFSCRIPT_DEBUG_H

#include "chunk.h"

// These methods just disassemble some instructions to be huamn readable
void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);

#endif