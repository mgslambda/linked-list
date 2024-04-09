#include "../include/list.h"

int main() {
    List *l = ll_init();
    ll_insert(l, 0, 50);
    ll_print_list(l);

    // remove when only one item in list
    ll_remove(l, 0);

    ll_insert(l, 0, 6);
    ll_insert(l, 0, 12);
    ll_insert(l, 0, 91);
    ll_insert(l, 0, 32);
    ll_insert(l, 0, 111);
    ll_print_list(l);

    // remove from list with several items
    ll_remove(l, 2);
    ll_print_list(l);

    // remove tail
    ll_remove(l, ll_size(l) - 1);
    ll_print_list(l);
}

