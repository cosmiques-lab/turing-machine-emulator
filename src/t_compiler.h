//
// Created by bodhi
//

#ifndef TURING_MACHINE_EMULATOR_T_COMPILER_H
#define TURING_MACHINE_EMULATOR_T_COMPILER_H

#include "turing_machine.h"

typedef struct t_expression_row {
    char *state;
    char *str_read;
    char *str_write;
    char *next_state;
    char *move;
    int error_type;
    int error_line;
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
 * @param str_in
 * @return char** splitted from row @str_in
 */
char** t_trim_expression ( char* );

/**
 * funzione di partenza, il char* in ingresso è la stringa totale del codice passato
 *  la funzione splitterà le righe del codice, e chiamerà @evaluate_row per ogni riga.

 *  mi creo poi un array di expression_row, da mandare in valutazione.
 *   *    chiama il @evaluate_next_state dove in base alla struttura creata dal @enqueue_expression mi chiama il @modify_machine per effettuare l'operazione

 * @return
 */
expression_row** evaluate_code ( char* );

/**
 * todo modifica documentazione
 *    OK chiamo il @t_lex_evaluate_row per valutare che sia nella forma corretta: (stato_iniziale (if[se] <char_letto> stato_se_true [stato_se_false]) <char_scritto> movimento)
 *    OK io passo la stringa normale, chiamo il @t_trim_expression che mi mette in un array di stringhe tutta la riga.
 *    OK chiamo il @evaluate_expression che mi valuta gli (eval) e i (not) [questo metodo sarà molto complesso perchè mi gestirà anche le espressioni molto annidate [deve pure riconoscere a partire da una riga in ingresso (in char**) tutte le espressioni di eval e not.
 *    OK chiamo il @enqueue_expression che mi creerà una struttura definita
 *
 * @param str_in
 * @param row_machine
 * @return -1 if brackets are incorrect
 *         -2 if the code string if not correct
 *         -3 alphabet is not correct
 *         -4 if there are difference between string read and string to write
 *         0 if correct
*/
int evaluate_row ( char*, expression_row* );

/**
 *  mi valuta gli @eval e i @not
 *
 * @return 0 se tutto corretto,
 *         -1 se l'alfabeto non va bene
 *         -2 se ci sono differenze di lunghezza
 */
int evaluate_expression ( char** );

/**
*
* @param row
* @return
*/
void enqueue_expression ( char **, expression_row* );

#endif //TURING_MACHINE_EMULATOR_T_COMPILER_H
