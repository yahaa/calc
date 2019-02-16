//
// Created by zihua on 2019/2/16.
//

#ifndef CALC_CHAR_STACK_H
#define CALC_CHAR_STACK_H
// stack 定义一个 字符栈 结构体
typedef struct char_stack {
    char *arr;
    int len;
} char_stack;


// push 向栈顶插入一个元素
void char_stack_push(char_stack *s, char a);

// pop 栈的出栈操作，pop 并且返回栈顶元素
char char_stack_pop(char_stack *s);

// top 获取栈顶元素(不删除)
char char_stack_top(char_stack *s);

char_stack *new_char_stack();


#endif //CALC_CHAR_STACK_H
