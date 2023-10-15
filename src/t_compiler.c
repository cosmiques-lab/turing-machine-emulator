//
// Created by Matteo Fiori on 13/10/23.
//

#include "t_compiler.h"
#include "utils.h"
#include "t_lex_parser.h"
#include <stdlib.h>
#include <string.h>

char** t_trim_expression ( char* str_in ) {
    char** trim_out = (char**) malloc(sizeof(char*) * 2000);
    int h = 0;
    int i = 0;

    while (i < length(str_in)) {

        if (str_in[i] == '(' || str_in[i] == ')') {
            i++;
            continue;
        }
        char* state_name = (char*) malloc(sizeof(char) * 200);
        int i_state = 0;
        do {
            state_name[i_state++] = str_in[i++];
        } while (str_in[i] != ' ' && str_in[i] != '\0');

        char *new_s = (char*) malloc(sizeof(char) * 200);
        int hq = 0;
        for(int q = 0; q< length(state_name);q++) {
            if (state_name[q] != ' ' && state_name[q] != '(' && state_name[q] != ')') {
                new_s[hq++] = state_name[q];
            }
        }
        trim_out[h++] = new_s;
    }

    return trim_out;
}

char* eval (char* str_in) {
    char* str_out = (char *) malloc(sizeof (char) * ALPHABET_SIZE);

    int h_str_out = 0;

    int i = 0;
    while (i < length(str_in)) {
        if (str_in[i] == '.') {
            char *s_tmp = get_expandable (str_in [i-1], str_in[i+1]);
            int j = 0;
            while (j < length(s_tmp)) {
                str_out[h_str_out++] = s_tmp[j++];
            }
        } else {
            str_out[h_str_out++] = str_in[i];
        }
        i++;
    }

    return str_out;
}

char* not (char* str_in) {
    char* str_out = (char *) malloc(sizeof (char) * ALPHABET_SIZE);
    int h = 0;

    int i = 0;
    while (i < ALPHABET_SIZE) {
        char c = get_char_in_alphabet(i);

        if (is_in (c, str_in) != 0) {
            str_out[h++] = c;
        }
        i++;
    }

    return str_out;
}


 void enqueue_expression ( char ** row, expression_row* exp_row ) {
    exp_row->state = row[0];
    exp_row->str_read = row[1];
    exp_row->next_state = row[2];
    exp_row->str_write = row[3];
    exp_row->move = row[4];
}

int evaluate_expression ( char** str_in ) {
    int i = 0;
    do {
        if (strcmp(str_in[i], "eval") == 0) {
            char *to_eval = eval(str_in[i+1]);
            str_in[i] = to_eval;
            str_in[++i] = "";
            i++;
            do {
                str_in[i-1] = str_in[i];
                i++;
            } while (str_in[i] != NULL);
            str_in[i-1] = NULL;
            i = 0;
        } else if (strcmp (str_in[i], "not") == 0) {
            if (strcmp(str_in[i+1], "eval") != 0) {
                char *to_eval = not (str_in [i+1]);
                str_in[i] = to_eval;
                str_in[++i] = "";
                i++;
                do {
                    str_in[i-1] = str_in[i];
                    i++;
                } while (str_in[i] != NULL);
                str_in[i-1] = NULL;
                i = 0;
            } else {
                i++;
            }
        } else {
            i++;
        }
    } while (str_in[i] != NULL);

    if (t_lex_str_alphabet (str_in[1]) == -1 || t_lex_str_alphabet (str_in[3]) == -1) {
        return -1;
    }

    if (compare_str_in_out(str_in[1], str_in[3]) != 0) {
        return -2;
    }

    return 0;
}

expression_row** evaluate_code ( char* code ) {

    char** rows = split_code_into_rows (code);

    expression_row** operations = (expression_row**) malloc(sizeof (expression_row*) * 2000);

    int i = 0;
    do {
        char* row = rows[i];
        expression_row* expr_row = (expression_row*) malloc (sizeof (expression_row));

        int eval_row = evaluate_row(row, expr_row);

        if (eval_row == 0) {
            operations[i] = expr_row;
        } else {
            // gestione dell'errore
        }
        i++;
    } while (rows[i] != NULL);

    return operations;
}

int evaluate_row ( char* str_in, expression_row* row_machine ) {
    if (t_lex_evaluate_row (str_in) == -1) {
        return -1;
    }

    char** trim_str = t_trim_expression( str_in );
    if (t_lex_evaluate_trim (trim_str) == -1) {
        return -2;
    }

    int ev_exp = evaluate_expression( trim_str );
    if (ev_exp == -1) {
        return -3;
    } else if (ev_exp == -2) {
        return -4;
    }

     enqueue_expression(trim_str, row_machine);

    return 0;
}