//
// Created by bodhi
//

#include <stdio.h>
#include "t_compiler.h"
#include "turing_machine.h"
#include "evaluation_machine.h"


void print_error (int err_type, int err_line) {

}

void print_machine ( t_machine* machine ) {
    
}

void run ( int sec_time, char* tape_str, char* code_str) {
    expression_row** code = evaluate_code (code_str);
    if (code[0]->error_type < 0) {
        print_error (code[0]->error_type, code[0]->error_line);
        return;
    }

    t_machine* t = init_machine(tape_str);

    // todo da rifare con visualizzazione a tempo
    machine_evaluate(code, t);

}

int main () {
    printf("starting turing machine emulator\n");

    // leggi i parametri

    // leggi da file

    // converti il file in un char*

    // chiama il run (char*, char*)
}