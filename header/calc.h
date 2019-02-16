//
// Created by zihua on 2019/2/16.
//

#ifndef CALC_CALC_H
#define CALC_CALC_H

// 获取优先级
int get_pri(char ch);

// addTrim 在字符串后面添加 '#'
char *add_trim(char const *input);

// last_order 输入中序表达式，输出后续表达式
char *last_order(char const *str);

int calc(char *l);


#endif //CALC_CALC_H
