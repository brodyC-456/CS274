#include <stdio.h>
#include "llist.h"

int main(void)
{
    struct llist *llist = llist_new();

    for (int i = 10; i <= 40; i += 10) {
        llist_insert(llist, i);
        llist_print(llist);
    }

    llist_drain(llist);
    llist_print(llist);
    llist_free(llist);
}