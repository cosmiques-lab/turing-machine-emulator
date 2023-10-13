//
// Created by Matteo Fiori on 13/10/23.
//

#ifndef TURING_MACHINE_EMULATOR_UTILS_H
#define TURING_MACHINE_EMULATOR_UTILS_H

#define ALPHABET_SIZE 87

char get_char_in_alphabet ( int );
char* get_expandable (char, char);
int find_position_in_alphabet (char);
int length(char*);
int is_in (char, char*);

#endif //TURING_MACHINE_EMULATOR_UTILS_H
