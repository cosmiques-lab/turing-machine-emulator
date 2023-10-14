//
// Created by Matteo Fiori on 13/10/23.
//

#include "t_compiler.h"
#include "utils.h"
#include "t_lex_parser.h"
#include <stdlib.h>
#include <string.h>

/**
 * TODO IN PROGRESS
 * la forma sarà:
 *
 *   (stato_iniziale <char_letto> stato_successivo <char_scritto> movimento)

 potrebbe crearmelo tipo
 stato_iniziale
 if[se]
 char_letto
 stato_se_true
 [stato_se_false]
 char_Scritto
 movimento

 ad esempio:
 (init (eval A.Z) letto_maiusc (eval a.z) right)

 init
 eval
 A.Z
 letto_maiusci
 eval
 a.z
 right

cosi poi ciclo la lista col @evaluate_expression e se trovo eval guardo e sostituisco le stringhe col valore, quindi mi diventa

  init
 ABCDEFGHIJKLMOPQRSTUVWXYZ
 letto_maiusci
 abcdefghijklmopqrstuvwxyz
 right

 poi chiamo @enqueue_expression che mi creerà una strtuttura:

 {
 state      = init
 str_read   = ABCDEFGHIJKLMOPQRSTUVWXYZ
 str_write  = abcdefghijklmopqrstuvwxyz
 next_state = letto_maiusci
 move       = righe
 }

 il @evaluate_next_state prende in input l'array di @t_expression_row e mi va a chiamare l'ultimo step di modifica @modify_machine,
 dove va a leggere effettivamente il nastro della macchina per capire cosa scrivere.

 */

// todo ha qualche bug
char** t_trim_expression ( char* str_in ) {
    char** trim_out = (char**) malloc(sizeof(char*) * 2000);
    int h = 0;

    int i = 0;

    int found_read_expression = -1;
    int read_chars = -1;
    int new_state = -1;
    int move = -1;
    while (i < length(str_in)) {

        // first state
        if (i == 1) {
            char* state_name = (char*) malloc(sizeof(char) * 200);
            int i_state = 0;
            do {
                state_name[i_state++] = str_in[i++];
            } while (str_in[i] != ' ');

            trim_out[h++] = state_name;

            if (str_in[i++] == '(') {
                found_read_expression = 0;
            }

            continue;
        }

        // todo da rivedere perchè non voglio più le parentesi..
        if (found_read_expression == 0) {
            if (str_in[i] == 'e') {
                if (str_in[i+1] == 'v' && str_in[i+2] == 'a' && str_in[i+3] == 'l' && str_in[i+4] == ' ') {
                    // eval TODO da mettere in un metodo apposta
                    char* tmp = (char*) malloc(sizeof(char*) * 5);
                    tmp[0] = str_in[i];
                    tmp[1] = str_in[i+1];
                    tmp[2] = str_in[i+2];
                    tmp[3] = str_in[i+3];
                    tmp[4] = '\0';
                    trim_out[h++] = tmp;
                    i = i+5;
                    if (str_in[i] == '(') {
                        continue;
                    } else {
                        char* tmp_str_in = (char*) malloc(sizeof(char) * ALPHABET_SIZE);
                        int k = 0;
                        while (str_in[i] != ')') {
                            tmp_str_in[k++] = str_in[i++];
                        }
                        trim_out[h++] = tmp_str_in;
                        continue;
                    }
                }
            } else if (str_in[i] == 'n') {
                if (str_in[i+1] == 'o' && str_in[i+2] == 't' && str_in[i+3] == ' ') {
                    // not TODO da mettere in un metodo apposta
                    char* tmp = (char*) malloc(sizeof(char*) * 4);
                    tmp[0] = str_in[i];
                    tmp[1] = str_in[i+1];
                    tmp[2] = str_in[i+2];
                    tmp[3] = '\0';
                    trim_out[h++] = tmp;

                    i = i+4;
                    if (str_in[i] == '(') {
                        continue;
                    } else {
                        char* tmp_str_in = (char*) malloc(sizeof(char) * ALPHABET_SIZE);
                        int k = 0;
                        while (str_in[i] != ')') {
                            tmp_str_in[k++] = str_in[i++];
                        }
                        trim_out[h++] = tmp_str_in;
                        continue;
                    }
                }
            }

            // controlla parentesi successiva se andare a leggere uno stato, quindi resetti il found_read_expression, o lo tieni a true
            found_read_expression = -1; // todo poi cambia
            i++;
            continue;
        } else if (found_read_expression == -1 && read_chars == -1) {
            // todo leggi la stringa



            read_chars = 0;

            i++;
            continue;
        }

        if (new_state == -1) {
            char* state_name = (char*) malloc(sizeof(char) * 200);
            int i_state = 0;
            do {
                state_name[i_state++] = str_in[i++];
            } while (str_in[i] != ' ');

            trim_out[h++] = state_name;

            if (str_in[i++] == '(') {
                found_read_expression = 0;
                read_chars = -1;
            } else {
                found_read_expression = -1;
                read_chars = -1;
            }

            new_state = 0;
            continue;
        }

        if (move == -1) {
            char* move_name = (char*) malloc(sizeof(char) * 200);
            int i_state = 0;
            do {
                move_name[i_state++] = str_in[i++];
            } while (str_in[i] != ')');

            trim_out[h++] = move_name;
            break;
        }
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

/*
 * TODO
 */
expression_row* enqueue_expression ( char ** , t_machine machine) {

}


/**
 * todo da riscrivere tutto..
 * perchè
 *    // if e ifse non restituiscono una stringa, ma una coppia char_letto - stato, per cui:
 * @param str_in
 */
char* evaluate_expression ( char** str_in ) {
    char* str;
    int i = 0;
    do {
        str = str_in[i++];

        if (strcmp (str, "not") == 0) {
            return not (str_in[i+1]);
        }

        if (strcmp (str, "eval") == 0) {
            return eval(str_in[i+1]);
        }



    } while (str != NULL);

    return NULL;
}

/*
 * TODO
 */
int evaluate_row ( char* str_in, t_machine machine) {
}

