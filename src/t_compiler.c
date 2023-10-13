//
// Created by Matteo Fiori on 13/10/23.
//

#include "t_compiler.h"
#include "utils.h"
#include <stdlib.h>


/*
 * todo ci sarà un correttore sintattico per evitare di avere una str_in mal formata
 */
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


/**
 * todo
 * @param str_in
 * @return
 */
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

/**
 *
 * @param s_read
 * @param s_write
 * @return
 */
int compare_str_in_out (char* s_read, char *s_write) {
    return length(s_read) != length(s_write) ? -1 : 0;
}