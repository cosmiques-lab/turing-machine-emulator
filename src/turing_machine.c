//
// Created by bodhi
//

#include "turing_machine.h"

/**
 *
 * @param init_str
 * @return
 */
t_machine* init_machine ( char* init_str ) {
    t_machine* t = (t_machine*) malloc (sizeof (t_machine));

    int tape_len = (length(init_str) * 2)+1;
    t->tape_ = (char*) malloc(sizeof (char) * tape_len);

    int center = (length(init_str)/2);

    int i = 0;
    int j = 0;
    while (i < tape_len) {
        if (i < center) {
            t->tape_[i] = '-';
        } else {
            if (init_str[j] == '\0') {
                t->tape_[i] = '-';
            } else {
                t->tape_[i] = init_str[j++];
            }
        }
        i++;
    }

    t->pointer_ = center;

    return t;
}

char get_read_char ( t_machine* t) {
    return t->tape_[t->pointer_];
}

void write_char ( char c, t_machine* t) {
    t->tape_[t->pointer_] = c;
}

void move_right ( t_machine* t) {
    int pointer_next = t->pointer_ + 1;

    if (t->tape_[pointer_next] == '\0') {
        int old_length = length(t->tape_);
        char* new_tape = (char*) malloc(sizeof(char) * old_length*2);

        int i = 0;
        while (i < old_length) {
            new_tape[i] = t->tape_[i];
            i++;
        }
        while (i < old_length * 2) {
            new_tape[i] = '-';
            i++;
        }

    }
    t->pointer_ = pointer_next;
}

void move_left ( t_machine* t ) {
    int pointer_next = t->pointer_ - 1;

    if (pointer_next < 0) {
        int old_length = length(t->tape_);
        char* new_tape = (char*) malloc(sizeof(char) * old_length*2);

        int i = 0;
        while (i < old_length) {
            new_tape[i] = '-';
            i++;
        }
        int j = 0;
        while (i < old_length*2) {
            new_tape[i] = t->tape_[j++];
            i++;
        }
        pointer_next = old_length;
    }
    t->pointer_ = pointer_next;
}