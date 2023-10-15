//
// Created by bodhi
//

#include "evaluation_machine.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>

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

int machine_evaluate ( expression_row** rows, t_machine* t, int speed) {
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

                modify_status(char_to_write, exp->move, t, speed);

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

void modify_status ( char c, char* move, t_machine* t, int speed) {
    write_char(c, t);

    if (strcmp(move, "right") == 0) {
        move_right(t);
    } else if (strcmp(move, "left") == 0) {
        move_left(t);
    }

    print_machine(t, speed);
}

void print_machine (t_machine* t, int speed) {
    printf("      %s      \n", t->tape_);

    int space_pointer = t->pointer_;
    char* spaces = (char*) malloc (sizeof(char) * space_pointer);
    for (int i = 0; i < space_pointer; i++) {
        spaces[i] = ' ';
    }

    printf("     %s|\n", spaces);
    sleep(speed);
}