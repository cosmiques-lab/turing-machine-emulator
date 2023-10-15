//
// Created by bodhi
//

#ifndef TURING_MACHINE_EMULATOR_T_LEX_PARSER_H
#define TURING_MACHINE_EMULATOR_T_LEX_PARSER_H


/**
 *
 * @param rows
 * @return 0 if trim rows are ok, -1 otherwise
 */
int t_lex_evaluate_trim ( char** );

/**
 *
 * @param row
 * @return 0 if @row is correctly written with brackets
 */
int t_lex_evaluate_row ( char* );

/**
 *
 * @param str_in
 * @return if @str_in contains all character from alphabet
 */
int t_lex_str_alphabet ( char * );

/**
 *
 * @param str_in
 * @return 0 if regex @str_in is correct, -1 otherwise
 */
int t_lex_str_regex ( char* );

/**
 *
 * @param str_in
 * @return if @str_in is a regex expression
 */
int is_regex_expression ( char* );


#endif //TURING_MACHINE_EMULATOR_T_LEX_PARSER_H
