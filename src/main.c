//
// Created by Matteo Fiori on 13/10/23.
//

#include <stdio.h>
#include "t_compiler.h"

void test() {
    char* eval_1 = eval("A.G");
    char* eval_2 = eval("A.A");
    char* eval_3 = eval("A.c");
    char* eval_4 = eval("0.9");
    char* eval_5 = eval("A.Z0.9");
    char* eval_6 = eval("a.gABC0.3.7");
    printf("(eval A.G) = %s\n", eval_1);
    printf("(eval A.A) = %s\n", eval_2);
    printf("(eval A.c) = %s\n", eval_3);
    printf("(eval 0.9) = %s\n", eval_4);
    printf("(eval A.Z0.9) = %s\n", eval_5);
    printf("(eval a.gABC0.3.7) = %s\n", eval_6);

    char* not_1 = not("ABCDEFGabcdefg01234!");
    printf("(not ABCDEFGabcdefg01234!) = %s\n", not_1);
}

int main () {
    printf("turing machine emulator\n");
    test();
}