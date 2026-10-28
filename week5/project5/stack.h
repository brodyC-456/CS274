#ifndef STACK_H
#define STACK_H

struct stack {
    struct node *top;
};

struct node {
    float value;
    struct node *next;
};

void push(struct stack *s, float value);
float pop(struct stack *s);
void stack_print(struct stack *s);

#endif