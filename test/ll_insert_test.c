#include "../include/list.h"

int main() {
    List *l = ll_init();
    ll_insert(l, 0, 5);
    ll_insert(l, 0, 23);
    ll_insert(l, 0, 65);
    ll_insert(l, 0, 3);
    ll_insert(l, 0, 102);
    ll_insert(l, 0, 56);
    ll_print_list(l);
    ll_insert(l, 3, 220);
    ll_print_list(l);
    ll_insert(l, 5, 1025);
    ll_print_list(l);
    ll_add_tail(l, 7);
    ll_print_list(l);
}

