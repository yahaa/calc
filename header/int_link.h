//
// Created by zihua on 2019/2/16.
//

#ifndef CALC_INT_LINK_H
#define CALC_INT_LINK_H

// int 类型的双向链表节点
typedef struct int_node {
    int value;
    struct int_node *pre;
    struct int_node *next;
} int_node;

// int 类型的链表
typedef struct int_link {
    int_node *head;
    int_node *tail;
    int len;
} int_link;

// 向尾部添加节点
void link_append(int_link *link, int value);

// 向头部添加一个节点
void link_insert(int_link *link, int value);

// 删除头部并且返回头结点
int link_top(int_link *link);

// 获取头结点的值
int link_head(int_link *link);

// 获取尾部节点的值
int link_tail(int_link *link);

// 删除尾部节点并且返回尾部节点的值
int link_pop(int_link *link);

int_node *new_int_node(int value);

int_link *new_int_link();

void free_int_link(int_link *link);


#endif //CALC_INT_LINK_H
