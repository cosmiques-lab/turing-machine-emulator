cmake_minimum_required(VERSION 3.26)
project(turing_machine_emulator C)

set(CMAKE_C_STANDARD 11)

add_executable(turing_machine_emulator
        src/t_compiler.c
        src/main.c
        src/utils.h
        src/utils.c)
