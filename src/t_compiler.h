//
// Created by Matteo Fiori on 13/10/23.
//

#ifndef TURING_MACHINE_EMULATOR_T_COMPILER_H
#define TURING_MACHINE_EMULATOR_T_COMPILER_H

// COMPILER KEYWORDS

/**
 *
 * @return
 */
char* eval ( char* );

/**
 *
 * @return
 */
char* not ( char* );


/**
 *
 * @param s_read
 * @param s_write
 * @return
 */
int compare_str_in_out (char* s_read, char *s_write);
#endif //TURING_MACHINE_EMULATOR_T_COMPILER_H
