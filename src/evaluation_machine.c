//
// Created by bodhi
//

#include "evaluation_machine.h"

#include <string.h>

int* search_status ( char* status, expression_row** rows) {
    int* init_n = (int*) malloc(sizeof(int) * 2000); // TODO da mettere un length
    int i = 0, j = 0;
    int found = -1;
    do {
        if (strcmp(rows[i]->state, status) == 0) {
            init_n[j++] = i;
            found = 0;
        }
        i++;
    } while (rows[i] != NULL);
    if (found == 0) {
        init_n[i] = -1;
    } else {
        init_n[0] = -1;
    }
    return init_n;
}

// TODO da rifare con metodo di visualizzazione riga per riga
int machine_evaluate ( expression_row** rows, t_machine* t) {
    char* status_name = "init";
    int* status = search_status(status_name, rows);
    do {
        int i = 0;
        int found_char = -1;
        while (status[i] != -1) {
            expression_row* exp = rows[i];
            char machine_char = get_read_char(t);
            char* chars_read = exp->str_read;

            if (is_in (machine_char, chars_read) == 0) {
                found_char = 0;
                char* chars_to_write = exp->str_write;
                int position_alphabet = get_position_in_string (machine_char, chars_read);
                char char_to_write = chars_to_write[position_alphabet];
                write_char(char_to_write, t);

                if (strcmp(exp->move, "right") == 0) {
                    move_right(t);
                } else if (strcmp(exp->move, "left") == 0) {
                    move_left(t);
                }

                status_name = exp->next_state;
                break;
            }

            i++;
        }

        if (found_char == -1) {
            status[0] = -1;
        } else {
            status = search_status(status_name, rows);
        }

    } while (status[0] != -1);

    return 0;
}