//
// Created by Matteo Fiori on 13/10/23.
//

#include <stdio.h>
#include "t_compiler.h"
#include "turing_machine.h"

void test() {
    char* row_1 = "(init (not (eval A.C)) end (not (eval a.c)) stay)";

    t_machine* test_machine = init_machine("CIAO");     // macchina di test a NULL x le operazioni sulle stringhe
    expression_row** code = evaluate_code (row_1);



}

int main () {
    printf("turing machine emulator\n");

    /**
     * Passaggi da fare nel main.c
     *  1. lettura di un file passato in input
     *  2. in input va passato anche la stringa di input (sennò stringa vuota) e la velocità di esecuzione tipo -vN
     *
     *   ./t_machine "STRINGA_INIZIALE" text.t -v 1
     *
     *   -v 1 vuol dire una riga x secondo, che è il valore di defaul se non specificato
     *
     *  3. crea una macchina di turing con nastro popolato e testina all'inizio della stringa
     *  4. chiama @evaluate_code, splitta le righe del file e per ogni riga chiama @evaluate_row
     *
     *  il file main.c serve solo per mostrare la macchina di turing che avanza di stato
     */


    /**
     *
     */
    test();
}