//
// Created by Matteo Fiori on 14/10/23.
//

#include "t_lex_parser.h"
#include "utils.h"


int t_lex_evaluate_row (char** row) {
    // TODO
    return 0;
}


int t_lex_str_alphabet ( char * str_in ) {
    int i = 0;
    while (i < length(str_in)) {
        if (find_position_in_alphabet(str_in[i]) == -1 && str_in[i] == '.') {
            return -1;
        }
        i++;
    }
    return 0;
}


int t_lex_str_regex ( char* str_in ) {
    if (str_in[0] == '.') {
        return -1;
    }

    if(str_in[length(str_in) - 1] == '.') {
        return -1;
    }

    return 0;
}


int is_regex_expression ( char* str_in ) {
    int i = 0;
    int is_regex = -1;
    while (i < length(str_in)) {
        if (str_in[i] == '.') {
            is_regex = 0;
            break;
        }
        i++;
    }
    return is_regex;
}


