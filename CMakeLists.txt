cmake_minimum_required(VERSION 3.26)
project(leafscript C)

set(CMAKE_C_STANDARD 17)

add_executable(leafscript src/main.c
        src/chunk.h
        src/chunk.c)
