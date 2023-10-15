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
int machine_evaluate ( expression_row**, t_machine* );

#endif //TURING_MACHINE_EMULATOR_EVALUATION_MACHINE_H
