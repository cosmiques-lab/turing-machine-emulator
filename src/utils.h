//
// Created by bodhi
//

#ifndef TURING_MACHINE_EMULATOR_UTILS_H
#define TURING_MACHINE_EMULATOR_UTILS_H

#define ALPHABET_SIZE 87

/**
 *
 * @param i
 * @return the char in alphabet at position @i
 */
char get_char_in_alphabet ( int );

/**
 *
 * @param c_from
 * @param c_to
 * @return all alphabet chars between @c_from and @c_to excluded
 */
char* get_expandable (char, char);

/**
 *
 * @param c
 * @return position in alphabet of input char @c
 */
int find_position_in_alphabet (char);

/**
 *
 * @param str
 * @return length of @str input string
 */
int length(char*);

/**
 *
 * @param c
 * @param str
 * @return 0 if @c is in @str
 */
int is_in (char, char*);

/**
 *
 * @param s_read
 * @param s_write
 * @return 0 if @s_read is same length of @s_write
 */
int compare_str_in_out (char* s_read, char *s_write);

/**
 *
 * @param code
 * @return array of lines, divided by \n char
 */
char** split_code_into_rows ( char* );

/**
 *
 * @param c
 * @param str
 * @return
 */
int get_position_in_string (char, char*);

/**
 *
 * @return
 */
char* get_alphabet ();
#endif //TURING_MACHINE_EMULATOR_UTILS_H
