//
// Created by elliot alderson on 14/10/2023.
//

#include <stdlib.h>

#include "memory.h"
#include "vm.h"

// Kinda just call realloc BUT make sure that the new size is actually valid
// This returns pointer to the result

void* reallocate(void* pointer, size_t oldSize, size_t newSize) {
    if(newSize == 0) {
        free(pointer);
        return NULL;
    }

    void* result = realloc(pointer, newSize);

    if(result == NULL) exit(1);

    return result;
}

static void freeObject(Obj* object) {
    switch(object->type) {
        case OBJ_STRING: {
            ObjString* string = (ObjString*)object;
            FREE_ARRAY(char, string->chars, string->length + 1);
            FREE(ObjString, object);
            break;
        }
    }
}

void freeObjects() {
    Obj* object = vm.objects;
    while(object != NULL) {
        Obj* next = object->next;
        freeObject(object);
        object = next;
    }
}