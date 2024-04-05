#ifndef _LIST_H
#define _LIST_H

#include <stddef.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

struct list {
    Node *head;
    Node *tail;
    size_t size;
};

#endif
