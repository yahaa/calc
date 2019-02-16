//
// Created by zihua on 2019/2/16.
//

// 运算符优先级表
// +、- ---> 5
// *、/ ---> 6

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "../header/char_stack.h"
#include "../header/int_link.h"

// 获取优先级
int get_pri(char ch) {
    if (ch == '+' || ch == '-') {
        return 5;
    }

    if (ch == '*' || ch == '/') {
        return 6;
    }

    return 0;
}

// addTrim 在字符串后面添加 '#'
char *add_trim(char const *input) {
    int len = 0;
    char *output = (char *) malloc(sizeof(char));
    while (input[len] != '\0') {
        output[len] = input[len];
        len++;
    }
    output[len++] = '#';
    output[len] = '\0';
    return output;
}

// last_order 输入中序表达式，输出后续表达式
char *last_order(char const *str) {
    char *input = add_trim(str);

    char_stack *opStack = new_char_stack(); // 运算符栈
    char *l = (char *) malloc(sizeof(char));
    int len = 0;


    char_stack_push(opStack, '#');

    size_t n = strlen(input);


    for (int i = 0; i < n; i++) {
        char t = input[i];
        if (t >= 48 && t <= 57) {
            l[len++] = t;
        } else if (t == '+' || t == '-' || t == '*' || t == '/') {
            int p1 = get_pri(t);
            int p2 = get_pri(char_stack_top(opStack));
            if (p1 > p2) {
                char_stack_push(opStack, t);
            } else {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
                char_stack_push(opStack, t);
            }
        } else if (t == '(') {
            char_stack_push(opStack, t);
        } else if (t == ')') {
            while (char_stack_top(opStack) != '(') {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
            }
            char_stack_pop(opStack); // 弹出 '('
        } else if (t == '#') {
            while (char_stack_top(opStack) != '#') {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
            }

            char_stack_pop(opStack); // 弹出 '#'
        } else {
            printf("unKnow char");
            return 1;
        }


    }

    l[len] = '\0';

    free(opStack->arr);
    free(opStack);
    free(input);

    return l;
}

int calc(char *l) {

    int_link *cal_link = new_int_link();
    int i = 0;


    while (l[i] != '\0') {
        if (l[i] >= 48 && l[i] <= 57) {
            int t = l[i] - 48;
            link_append(cal_link, t);
        } else {
            int p1 = link_pop(cal_link);
            int p2 = link_pop(cal_link);

            if (l[i] == '+') {
                link_append(cal_link, p1 + p2);
            }

            if (l[i] == '-') {
                link_append(cal_link, p1 - p2);
            }

            if (l[i] == '*') {
                link_append(cal_link, p1 * p2);
            }

            if (l[i] == '/') {
                link_append(cal_link, p1 / p2);
            }
        }
        i++;
    }

    int res = link_pop(cal_link);
    free_int_link(cal_link);

    return res;
}


