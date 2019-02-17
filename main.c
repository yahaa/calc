#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/int_link.h"
#include "header/char_stack.h"
#include "header/calc.h"


int main() {
    char *input = "-4000000-2*(-6666+2)*456";

    char *last = last_order(input);
    int t = calc(last);
    printf("%d\n", t);

}