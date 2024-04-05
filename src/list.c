#include <stdio.h>
#include <stdlib.h>
#include "../include/_list.h"
#include "../include/list.h"

static void _throw_error(char *);

List *ll_init() {
    List *l = malloc(sizeof *l);
    if (l == NULL) {
        _throw_error("Could not allocate memory for list");
    }
    l->head = malloc(sizeof *l->head);
    l->tail = malloc(sizeof *l->tail);
    l->size = 0;
    return l;
}

size_t ll_size(List *l) {
    return l->size;
}

size_t ll_is_empty(List *l) {
    return ll_size(l) == 0;
}

int ll_get_head(List *l) {
    if (ll_is_empty(l)) {
        _throw_error("Cannot get from an empty list");
    }
    return l->head->val;
}

int ll_get_tail(List *l) {
    if (ll_is_empty(l)) {
        _throw_error("Cannot get from an empty list");
    }
    return l->tail->val;
}

void ll_add_head(List *l, const int val) {
    Node *n = malloc(sizeof *n);
    if (n == NULL) {
        _throw_error("Could not allocate memory for list node");
    }
    n->val = val;
    if (ll_is_empty(l)) {
        n->next = NULL;
        l->head = l->tail = n;
    } else {
        n->next = l->head;
        l->head = n;
    }
    l->size++;
}

void ll_add_tail(List *l, const int val) {
    Node *n = malloc(sizeof *n);
    if (n == NULL) {
        _throw_error("Could not allocate memory for list node");
    }
    n->val = val;
    n->next = NULL;
    if (ll_is_empty(l)) {
        l->head = l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

int ll_remove_head(List *l) {
    if (ll_is_empty(l)) {
        _throw_error("Cannot remove from an empty list");
    }
    Node *old_head = l->head;
    int ret_val = old_head->val;
    l->head = l->head->next;
    if (ll_size(l) == 1) {
        l->tail = l->head;
    }
    free(old_head);
    l->size--;
    return ret_val;
}

void ll_print_list(List *l) {
    Node *current = l->head;
    while (current != NULL) {
        printf("%d->", current->val);
        current = current->next;
    }
    puts("NULL");
}

void ll_del_list(List *l) {
    while (l->head != NULL) {
        Node *current = l->head;
        l->head = l->head->next;
        free(current);
    }
    free(l);
}

static void _throw_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

