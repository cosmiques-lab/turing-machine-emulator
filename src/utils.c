//
// Created by bodhi
//

#include "utils.h"
#include <stdlib.h>

char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    '!', '@', '#', '$', '%', '&', '_', '=', '+', '[', ']', '{', '}', ';', ':', '"', '<', '>', ',', '/', '|', '~', '}', ';', '-'};

char get_char_in_alphabet ( int i ) {
    if (i < 0 || i > ALPHABET_SIZE - 1) {
        return '\0';
    }
    return alphabet[i];
}

int is_in (char c, char* str) {
    int i = 0;
    while (i < length(str)) {
        if (str[i] == c) {
            return 0;
        }
        i++;
    }
    return -1;
}

int length(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int find_position_in_alphabet (char c) {
    int i = 0;
    int found = -1;
    while (i < 87) {
        if (alphabet[i] == c) {
            found = 0;
            break;
        }
        i++;
    }

    if (found == 0) {
        return i;
    } else {
        return -1;
    }
}

char* get_expandable (char c_from, char c_to) {
    char* str_out = (char *) malloc(sizeof (char) * ALPHABET_SIZE);

    int i = find_position_in_alphabet(c_from) + 1;
    int j = 0;

    while (alphabet[i] != c_to) {
        str_out [j] = alphabet[i];
        i++;
        j++;
    }
    str_out[j++] = '\0';

    return str_out;
}

int compare_str_in_out (char* s_read, char *s_write) {
    if (length(s_read) == 1 && s_read[0] == '*') {
        return 0;
    }

    if (length(s_write) == 1 && s_write[0] == '?') {
        return 0;
    }

    return length(s_read) != length(s_write) ? -1 : 0;
}

/**
 *
 * @param code
 * @return
 */
char** split_code_into_rows ( char* code ) {
    int size = 2000;
    char** rows = (char**) malloc (sizeof(char*) * size);

    int i = 0;
    int j = 0;
    int h = 0;
    do {
        char c = code[h++];

        if (c == '\n') {
            i++;
            j = 0;
        } else {
            if (rows[i] == NULL) {
                rows[i] = (char*) malloc(sizeof (char) * size);
            }
            rows[i][j++] = c;
        }
    } while (code[h] != '\0');

    return rows;
}


int get_position_in_string (char c, char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

char* get_alphabet () {
    return alphabet;
}