//
// Created by bodhi
//

#ifndef TURING_MACHINE_EMULATOR_TURING_MACHINE_H
#define TURING_MACHINE_EMULATOR_TURING_MACHINE_H

#include <stdlib.h>
#include "utils.h"

typedef struct machine {
    char* tape_;
    int pointer_;
} t_machine;

/**
 *
 * @param init_str
 * @return
 */
t_machine* init_machine ( char* init_str );

/**
 *
 * @param t
 * @return
 */
char get_read_char ( t_machine* );

/**
 *
 * @param c
 * @param t
 */
void write_char ( char, t_machine* );

/**
 *
 * @param t
 */
void move_right ( t_machine* );

/**
 *
 * @param t
 */
void move_left ( t_machine* );

#endif //TURING_MACHINE_EMULATOR_TURING_MACHINE_H
