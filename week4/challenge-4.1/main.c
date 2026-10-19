#include <stdio.h>


int main(){
    char c = 'a';
    short s = 1;
    int i = 2;
    long l = 3;


    printf("%zu\n", sizeof c);
    printf("%zu\n", sizeof s);
    printf("%zu\n", sizeof i);
    printf("%zu\n", sizeof l);
    printf("%zu\n", sizeof(s + i));
    printf("%zu\n", sizeof 12);
    printf("%zu\n", sizeof 20);
    printf("%zu\n", sizeof 3.14);

    printf("%zu\n", sizeof (char));
    printf("%zu\n", sizeof (int));
    printf("%zu\n", sizeof (long));
    printf("%zu\n", sizeof (float));
    printf("%zu\n", sizeof (double));

    int *p;
    p  = &i;

    long *q;
    q = &l;

    printf("%zu\n", sizeof p);
    printf("%zu\n", sizeof q);

    printf("%zu\n", sizeof (char*));
    printf("%zu\n", sizeof (int*));
    printf("%zu\n", sizeof (long*));
    printf("%zu\n", sizeof (double*));
}


// 3.14 is a double
// 12 is an int
// The pointer types are all the same size because pointers are a fixed size

