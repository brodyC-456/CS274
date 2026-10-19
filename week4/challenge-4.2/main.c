#include <stdio.h>

void f1(int *x)
{
    printf("f1: sizeof x = %zu\n", sizeof x);
}

void f2(int x[])
{
    printf("f2: sizeof x = %zu\n", sizeof x);
}

void f3(int x[5])
{
    printf("f3: sizeof x = %zu\n", sizeof x);
}

int main(){
    char a[12];
    int b[4];

    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(int));

    printf("%zu\n", sizeof a);
    printf("%zu\n", sizeof b);

    printf("%zu\n", sizeof(b) / sizeof(int));
    printf("%zu\n", sizeof(b) / sizeof(b[0]));
    
    char *p;
    p = a;

    int *q;
    q = b;

    printf("%zu\n", sizeof p);
    printf("%zu\n", sizeof q);

    f1(b);
    f2(b);
    f3(b);

}

//Q1: Since our compiler knows the full size of a, it will print the full size in bytes of the whole array.
// The new pointer is just a pointer in the compilers eyes, so doing sizeof p will just give us 8.

//Q2: The type of x under the hood in all cases is a pointer, so every function parameter works because they're all pointers