#ifdef STACK_H
#define STACK_H

struct stack {
    struct node *top;
};

struct node {
    float value;
    struct node *next;
};

void push(struct stack, float);
float pop(struct stack);

#endif