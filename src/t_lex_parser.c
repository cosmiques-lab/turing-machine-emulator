//
// Created by bodhi
//

#include "t_lex_parser.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

int t_lex_evaluate_trim ( char** rows) {
    char* c;
    int i = 0;
    int counter = 0;

    int next_regex = -1;
    int next_not = -1;
    int not_param_regex = -1;
    do {
        c = rows[i++];
        if (strcmp(c, "") == 0) {
            continue;
        }

        if (next_regex == 0) {
            if (is_regex_expression (c) != 0 || t_lex_str_regex (c) != 0) {
                return -1;
            }
            next_regex = -1;
        }

        if (strcmp(c, "eval") == 0) {
            next_regex = 0;
            if (next_not == 0) {
                not_param_regex = -1;
            }
        } else if (strcmp(c, "not") == 0) {
            next_not = 0;
            not_param_regex = 0;
            counter++;
        } else {
            if (next_not == 0) {
                next_not = -1;

                if (not_param_regex == 0) {
                    if (is_regex_expression(c) == 0) {
                        return -1;
                    }
                    not_param_regex = -1;
                }
            } else {
                counter++;
            }
        }
    } while (rows[i] != NULL);

    return counter == 5 ? 0 : -1;
}

int t_lex_evaluate_row (char* row) {
    int i = 0, h = 0;
    char* brack = (char*) malloc (sizeof (char) * length(row));

    do {
        if (row[i] == '(' || row[i] == ')') {
            brack[h++] = row[i];
        }
        i++;
    } while (row[i] != '\0');

    int search_close = 0;
    for (i = 0; i < length(brack); i++) {
        if (search_close == 0 && brack[i] == '(') {
            brack[i] = 'X';
            search_close = -1;
        }  else if (search_close == -1 && brack[i] == ')') {
            brack[i] = 'X';
            search_close = 0;
            i = 0;
        }
    }

    if (length(brack) % 2 != 0) {
        return -1;
    }

    for (i = 0; i < length(brack); i++) {
        if (brack[i] == '(' || brack[i] == ')') {
            return -1;
        }
    }

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