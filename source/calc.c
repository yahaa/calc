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

// addTrim 在字符串后面添加 '#',并且处理掉 -9*1===> (0-9)*1 +9*1===>(0+9)*1
char *add_trim(char const *input) {
    int l1 = 0;
    int l2 = l1;
    char *output = (char *) malloc(1000);
    while (input[l1] != '\0') {
        int flag = 0;
        char t = input[l1];
        if (l1 == 0) {
            if (t == '-' || t == '+') {
                output[l2++] = '(';
                output[l2++] = '0';
                flag = 1;
            }
        } else {
            if ((t == '-' || t == '+') && (input[l1 - 1] < 48 || input[l1 - 1] > 57)) {
                output[l2++] = '(';
                output[l2++] = '0';
                flag = 1;
            }
        }

        output[l2++] = t;
        l1++;

        if (flag) {
            while (input[l1] >= 48 && input[l1] <= 57) {
                output[l2++] = input[l1++];
            }
            output[l2++] = ')';
        }
    }
    output[l2++] = '#';
    output[l2] = '\0';

    return output;
}

// last_order 输入中序表达式，输出后续表达式
char *last_order(char const *str) {
    char *input = add_trim(str);

    char_stack *opStack = new_char_stack(); // 运算符栈
    char *l = (char *) malloc(1000);
    int len = 0;


    char_stack_push(opStack, '#');

    size_t n = strlen(input);


    for (int i = 0; i < n; i++) {
        char t = input[i];
        if (t >= 48 && t <= 57) {
            int s = i;
            while (input[s] >= 48 && input[s] <= 57) {
                l[len++] = input[s];
                s++;
            }
            l[len++] = ' ';
            i = s - 1;

        } else if (t == '+' || t == '-' || t == '*' || t == '/') {
            int p1 = get_pri(t);
            int p2 = get_pri(char_stack_top(opStack));
            if (p1 > p2) {
                char_stack_push(opStack, t);
            } else {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
                l[len++] = ' ';
                char_stack_push(opStack, t);
            }
        } else if (t == '(') {
            char_stack_push(opStack, t);
        } else if (t == ')') {
            while (char_stack_top(opStack) != '(') {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
                l[len++] = ' ';
            }
            char_stack_pop(opStack); // 弹出 '('
        } else if (t == '#') {
            while (char_stack_top(opStack) != '#') {
                char tp = char_stack_pop(opStack);
                l[len++] = tp;
                l[len++] = ' ';
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

    size_t str_len = strlen(l);


    while (i < str_len) {

        if (l[i] == ' ') {
            i++;
            continue;
        }

        if (l[i] >= 48 && l[i] <= 57) {
            char *num = (char *) malloc(sizeof(char));
            int n = 0;
            int s = i;
            while (l[s] >= 48 && l[s] <= 57) {
                num[n++] = l[s];
                s++;
            }
            num[n] = '\0';

            int t = atoi(num);


            link_append(cal_link, t);

            i = s - 1;
        } else {
            int p2 = link_pop(cal_link);
            int p1 = link_pop(cal_link);

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
    free(l);

    return res;
}


