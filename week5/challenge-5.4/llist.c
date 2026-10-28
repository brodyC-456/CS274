#include <stdio.h>
#include <stdlib.h>
#include "llist.h"


/**
 * Create a new linked list with a NULL head pointer.
 */
struct llist *llist_new(void)
{
    struct llist *l = malloc(sizeof(*l));
    l->head = NULL;
    return l;
}

/**
 * Free all the nodes in the linked list and free the linked list
 * itself.
 */
void llist_free(struct llist *llist)
{
    llist_drain(llist);
    free(llist);
}

/**
 * Remove all the items from a linked list.
 */
void llist_drain(struct llist *llist)
{
    while(llist->head != NULL){
        struct node *n = llist->head;
        llist->head = llist->head->next;
        free(n);  
    }
}

/**
 * Insert a new value in the linked list.
 */
void llist_insert(struct llist *llist, int value)
{
    // TODO
    struct node *n = malloc(sizeof(*n));
    n->value = value;
    n->next = llist->head;
    llist->head = n;
}

/**
 * Print a linked list.
 */
void llist_print(struct llist *llist)
{
    if (llist->head == NULL)
        printf("[empty]");
    else
        for (struct node *n = llist->head; n != NULL; n = n->next)
            printf("(%d)%s", n->value, n->next == NULL? "": " -> ");

    putchar('\n');
}