#include <stdio.h>

int add(int x, int y);


int main(void)
{
    printf("1 + 2 = %d\n", add(1, 2));
}

int add(int x, int y)
{
    return x + y;
}