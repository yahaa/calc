#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/int_link.h"
#include "header/char_stack.h"
#include "header/calc.h"


int main() {
    char *input = "1+2+3";
    char *last = last_order(input);

    printf("%s\n", last);

    int t = calc(last);
    printf("\n%d", t);

}