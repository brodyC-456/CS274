#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

void push(struct stack *s, float value){
    struct node *n = malloc(sizeof *n);
    n->value = value;
    n->next = s->top;
    s->top = n;
}

float pop(struct stack *s){
    struct node *current_top = s->top;
    if(current_top == NULL){
        puts("No Node in Stack!");
        return NAN;
    }
    struct node *next_top = current_top->next;
    float value = current_top->value;

    free(current_top);
    s->top = next_top;
    return value;
}
