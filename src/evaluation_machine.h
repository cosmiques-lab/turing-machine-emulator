//
// Created by bodhi
//

#ifndef TURING_MACHINE_EMULATOR_EVALUATION_MACHINE_H
#define TURING_MACHINE_EMULATOR_EVALUATION_MACHINE_H

#include "turing_machine.h"
#include "t_compiler.h"

/**
 *
 * @param status
 * @param rows
 * @return
 */
int* search_status ( char*, expression_row** );

/**
 *
 * @param operations
 * @param machine
 * @return
 */
int machine_evaluate ( expression_row**, t_machine*, int );

/**
 *
 * @param c
 * @param move
 * @param t
 * @param speed
 */
void modify_status ( char, char*, t_machine*, int );

/**
 *
 * @param t
 * @param speed
 */
void print_machine (  t_machine*, int );

#endif //TURING_MACHINE_EMULATOR_EVALUATION_MACHINE_H
