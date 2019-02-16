//
// Created by zihua on 2019/2/16.
//

#include <stdlib.h>
#include "../header/int_link.h"
#include <stdio.h>


int_node *new_int_node(int value) {
    int_node *node = (int_node *) malloc(sizeof(int_node));
    node->value = value;
    node->next = NULL;
    node->pre = NULL;
    return node;
}

int_link *new_int_link() {
    int_link *link = (int_link *) malloc(sizeof(int_link));
    link->head = NULL;
    link->tail = NULL;
    link->len = 0;
    return link;
}


// 向尾部添加节点
void link_append(int_link *link, int value) {
    int_node *node = new_int_node(value);

    if (link->len == 0) {
        link->tail = node;
        link->head = node;

    } else {
        node->pre = link->tail;
        link->tail->next = node;
        link->tail = node;
    }

    link->len++;
}

// 向头部添加一个节点
void link_insert(int_link *link, int value) {
    int_node *node = new_int_node(value);

    if (link->len == 0) {
        link->tail = node;
        link->head = node;
    } else {
        node->next = link->head;
        link->head->pre = node;
        link->head = node;
    }

    link->len++;
}


// 获取头结点的值
int link_head(int_link *link) {
    return link->head->value;
}

// 获取尾部节点的值
int link_tail(int_link *link) {
    return link->tail->value;
}

// 删除头部并且返回头结点
int link_top(int_link *link) {
    int_node *node = link->head;
    int res = node->value;

    if (link->len <= 1) {
        link->head = NULL;
        link->tail = NULL;
    } else {
        link->head = link->head->next;
        link->head->pre = NULL;
    }

    link->len--;

    free(node);

    return res;
}


// 删除尾部节点并且返回尾部节点的值
int link_pop(int_link *link) {
    int_node *node = link->tail;
    int res = node->value;

    if (link->len <= 1) {
        link->head = NULL;
        link->tail = NULL;
    } else {
        link->tail = link->tail->pre;
        link->tail->next = NULL;
    }


    link->len--;

    free(node);

    return res;
}


void free_int_link(int_link *link) {
    while (link->len > 0) {
        link_top(link);
    }

    free(link);
}




