#include <stdio.h>

int main(){
    int value1 = 37;
    int value2 = 3490;
    int *p;
    int *q;

    p = &value1;
    printf("value 1: %d\n", value1);
    printf("address of value 1: %p\n", &value1);
    printf("p: %p\n", p);
    printf("p points to: %d\n", *p);

    q = &value2;
    printf("value 2: %d\n", value2);
    printf("address of value 2: %p\n", &value2);
    printf("q: %p\n", q);
    printf("q points to: %d\n", *q);


    int *temp = p;
    p = q;
    q = temp;

    printf("value 1: %d, value 2: %d\n", value1, value2);

    p = q;

    printf("p points to: %d, q points to: %d\n", *p, *q);
    
    


}