//
// Created by Matteo Fiori on 13/10/23.
//

#include <stdio.h>
#include "t_compiler.h"
void test() {
    t_machine test_machine;     // macchina di test a NULL x le operazioni sulle stringhe

    /**
     *  esempio di lettura di @row_1
     * sei in stato init
     * se leggi A.Z vai in stato END
     * scrivi a.z
     * e rimani con la testina ferma.
     */
    char* row_1 = "(init (eval A.Z) end (eval a.z) stay)";
    char** row_split = t_trim_expression(row_1);

    printf("end test\n");

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