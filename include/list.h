#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct list List;
extern List *ll_init();
extern size_t ll_size(const List *l);
extern size_t ll_is_empty(const List *l);
extern int ll_get(const List *l, const size_t index);
extern int ll_get_tail(const List *l);
extern void ll_insert(List *l, const size_t index, const int val);
extern void ll_insert_tail(List *l, const int val);
extern int ll_remove(List *l, const size_t index);
extern void ll_print_list(const List *l);
extern void ll_del_list(List *l);

#endif
