//
// Created by bodhi
//

#include <stdio.h>
#include <string.h>
#include "t_compiler.h"
#include "turing_machine.h"
#include "evaluation_machine.h"

void print_error (int err_type, int err_line) {
    char* err_str = NULL;
    switch (err_type) {
        case -1:
            err_str = "brackes are incorrect";
            break;
        case -2:
            err_str = "syntax error";
            break;
        case -3:
            err_str = "character not found in alphabet";
            break;
        case -4:
            err_str = "difference size between read char and write char";
            break;
    }

    printf("error at line %d: %s\n", err_line+1, err_str);
}

void run ( char* tape_str, char* code_str, int speed) {
    expression_row** code = evaluate_code (code_str);
    if (code[0]->error_type < 0) {
        print_error (code[0]->error_type, code[0]->error_line);
        return;
    }

    t_machine* t = init_machine(tape_str);

    machine_evaluate(code, t, speed);

}

int main (int argc, char** argv) {
    printf("starting turing machine emulator\n");

    char* file_path = NULL;
    char* tape = NULL;
    FILE *f = NULL;

    char* row = (char*) malloc (sizeof(char) * 2000);
    char* code = (char*) malloc (sizeof(char) * 2000);
    int speed = 0;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            file_path = argv[i+1];
        } else if (strcmp(argv[i], "-v") == 0) {
            speed = atoi(argv[i+1]);
        } else if (strcmp(argv[i], "-t") == 0) {
            tape = argv[i+1];
        }
    }

    f = fopen(file_path, "r");
    if (f == NULL) {
        return -1;
    }
    while (fgets(row, 2000, f)) {
        strcat(code, row);
    }

    run(tape, code, speed);

    printf("end simulation\n");
    return 0;
}