#include <stdio.h>
#include "./include/list.h"

int main() {
    List *l = ll_init();
    ll_add_head(l, 5);
    ll_print_list(l);
    ll_add_tail(l, 7);
    ll_print_list(l);
    printf("List size = %lu\n", ll_size(l));
    ll_print_list(l);
    ll_remove_head(l);
    printf("List size = %lu\n", ll_size(l));
    ll_print_list(l);
    ll_add_tail(l, 42);
    printf("List size = %lu\n", ll_size(l));
    ll_print_list(l);
    ll_add_head(l, 101);
    ll_print_list(l);
    ll_del_list(l);
    puts("DONE");
}

