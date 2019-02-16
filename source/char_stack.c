//
// Created by zihua on 2019/2/16.
//

#include <stdlib.h>
#include "../header/char_stack.h"

// push 向栈顶插入一个元素
void char_stack_push(char_stack *s, char a) {
    s->arr[s->len] = a;
    s->len++;
}

// pop 栈的出栈操作，pop 并且返回栈顶元素
char char_stack_pop(char_stack *s) {
    char res = '\0';
    if (s->len == 0) {
        return res;
    }

    res = s->arr[s->len - 1];
    s->arr[s->len - 1] = '\0';
    s->len--;
    return res;
}

// top 获取栈顶元素(不删除)
char char_stack_top(char_stack *s) {
    if (s->len == 0) {
        return '\0';
    }

    return s->arr[s->len - 1];
}


char_stack *new_char_stack() {
    char_stack *s = (char_stack *) malloc(sizeof(char_stack)); // 给 s 分配堆内存地址
    s->arr = (char *) malloc(sizeof(char)); // s 的 arr 分配内存地址
    s->len = 0;
    return s;
}
