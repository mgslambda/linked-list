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

size_t ll_size(const List *l) {
    return l->size;
}

size_t ll_is_empty(const List *l) {
    return ll_size(l) == 0;
}

int ll_get(const List *l, const size_t index) {
    if (ll_is_empty(l))
        _throw_error("Cannot get from an empty list");
    if (index >= ll_size(l))
        _throw_error("Index out of bounds");
    Node *current = l->head;
    for (size_t i = 0; i < index; i++)
        current = current->next;
    return current->val;
}

int ll_get_tail(const List *l) {
    if (ll_is_empty(l))
        _throw_error("Cannot get from an empty list");
    return l->tail->val;
}

void ll_insert(List *l, const size_t index, const int val) {
    Node *n = malloc(sizeof *n);
    if (n == NULL)
        _throw_error("Could not allocate memory for list node");
    n->val = val;
    if (ll_is_empty(l)) {
        n->next = NULL;
        l->head = l->tail = n;
    } else if (index == 0) {
        n->next = l->head;
        l->head = n;
    } else {
        if (index >= ll_size(l))
            _throw_error("Index out of bounds. Use ll_insert_tail to add to end of the list");
        Node *current = l->head;
        for (size_t i = 0; i < index - 1; i++)
            current = current->next;
        n->next = current->next;
        current->next = n;
    }
    l->size++;
}

void ll_insert_tail(List *l, const int val) {
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

int ll_remove(List *l, const size_t index) {
    int ret_val;
    if (ll_is_empty(l))
        _throw_error("Cannot remove from an empty list");
    Node *current = l->head;
    if (ll_size(l) == 1) {
        ret_val = l->head->val;
        l->head = l->head->next;
        l->tail = l->head;
        free(current);
    } else {
        for (size_t i = 0; i < index - 1; i++)
            current = current->next;
        Node *remove_node = current->next;
        current->next = current->next->next;
        ret_val = remove_node->val;
        free(remove_node);
        if (index == ll_size(l) - 1)
            l->tail = current;
    }
    l->size--;
    return ret_val;
}

void ll_print_list(const List *l) {
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

