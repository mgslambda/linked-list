#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct list List;
extern List *ll_init();
extern size_t ll_size(List *);
extern size_t ll_is_empty(List *);
extern int ll_get(List *, size_t);
extern int ll_get_tail(List *);
extern void ll_add_head(List *, int);
extern void ll_add_tail(List *, int);
extern int ll_remove_head(List *);
extern void ll_print_list(List *);
extern void ll_del_list(List *);

#endif
