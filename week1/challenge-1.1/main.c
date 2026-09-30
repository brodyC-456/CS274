#include <stdio.h>

int main(void){
    int x = 6;
    int f;
    f = 3+4/(2*3*4)-4/(4*5*6)+4/(6*7*8)-4/(8*9*10)+4/(10*11*12);
    printf("%d is a good number\n", x);
    printf("%d is a terrible number\n", f);
    float g = 3+4.0/(2*3*4)-4/(4*5*6)+4/(6*7*8)-4/(8*9*10)+4/(10*11*12);
    printf("%f is still bad but its fine i guess\n", g);
    int k = g;
    printf("%d is an int\n", k);
    printf("%f is a string\n", g);
    printf("22 / 7: %f\n", 22.0/7.0);
    char *s = "This is a test";
    printf("The string is: %s\n", s);


}