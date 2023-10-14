//
// Created by Matteo Fiori on 13/10/23.
//

#ifndef TURING_MACHINE_EMULATOR_T_COMPILER_H
#define TURING_MACHINE_EMULATOR_T_COMPILER_H

#include "turing_machine.h"

/**
 * todo
 */
typedef struct t_expression_row {
    char *state;
    char *str_read;
    char *str_write;
    char *next_state;
    char *move;
} expression_row;

/**
 *
 * @param str_in
 * @return string result of <EVAL> keyword of @str_in expression
 */
char* eval ( char* str_in );

/**
 *
 * @param str_in
 * @return string result of <NOT> keyword of @str_in expression
 */
char* not ( char* str_in );

/**
 * splitta una stringa in un array di sotto-stringhe, cosi ho un'array con tutta l'espressione
 *
 * TODO DA SCRIVERE 0
 *  da finire (ho fatto solo eval, not e parentesi)
 * @param str_in
 * @return char** splitted from row @str_in
 */
char** t_trim_expression ( char* );

/** TODO DA SCRIVERE 3
 * funzione di partenza, il char* in ingresso è la stringa totale del codice passato
 *  la funzione splitterà le righe del codice, e chiamerà @evaluate_row per ogni riga.
 * @return
 */
int evaluate_code ( char*, t_machine );

/** TODO DA SCRIVERE 2
 *
 *    io passo la stringa normale, chiamo il @t_trim_expression che mi mette in un array di stringhe tutta la riga.
 *    chiamo il @t_lex_evaluate_row per valutare che sia nella forma corretta: (stato_iniziale (if[se] <char_letto> stato_se_true [stato_se_false]) <char_scritto> movimento) TODO FORSE È MEGLIO P[RIMA CHIAMARE QUESTO PER VEDERE CHE LE PARENTESI SIANO CORRETTE
 *    chiamo il @evaluate_expression che mi valuta gli (eval) e i (not) [questo metodo sarà molto complesso perchè mi gestirà anche le espressioni molto annidate [deve pure riconoscere a partire da una riga in ingresso (in char**) tutte le espressioni di eval e not.
 *    chiamo il @enqueue_expression che mi creerà una struttura definita da :
 *      stato_iniziale, char_letto, in quale stato andare, e come spostarsi.. quindi una lista di queste operazioni (definite da una struttura)
 *    chiama il @evaluate_next_state dove in base alla struttura creata dal @enqueue_expression mi chiama il @modify_machine per effettuare l'operazione
 * @return
 */
int evaluate_row ( char*, t_machine );

/** TODO DA SCRIVERE 1
 *  mi valuta gli (eval) e i (not) [questo metodo sarà molto complesso perchè mi gestirà anche le espressioni molto
 *  annidate [deve pure riconoscere a partire da una riga in ingresso (in char**) tutte le espressioni di eval e not
 * @return
 */
char* evaluate_expression ( char** );

/** TODO DA SCRIVERE 3
 * mi creerà una struttura definita da :
 *      stato_iniziale, char_letto, in quale stato andare, e come spostarsi.. quindi una lista di queste operazioni (definite da una struttura)
 * @return
 */
expression_row* enqueue_expression ( char ** , t_machine machine);

/**
 * TODO DA SCRIVERE 5
 * @param operations
 * @param machine
 * @return
 */
int evaluate_next_state ( expression_row* operations, t_machine machine );

/** TODO DA SCRIVERE 4
 *  effettua la modifica alla macchina di turing.
 *
 * @param move
 * @param c_write
 * @param machine
 * @return
 */
int modify_machine ( int move, char c_write, char* str_new_state, t_machine machine);

#endif //TURING_MACHINE_EMULATOR_T_COMPILER_H
