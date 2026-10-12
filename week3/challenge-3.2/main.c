#include <stdio.h>

// Compiler might warn on a being unused, but ignore it.
void bad_increment(int a)
{
    a++;
}

void good_increment(int *p){
    ++*p;
}

// void good_increment(... TODO, must return void

int main(void)
{
    int x = 12;

    bad_increment(x);
    printf("%d\n", x);  // 12, boo
    
    good_increment(&x);
    printf("%d\n", x);  // 13, yay!
    


}