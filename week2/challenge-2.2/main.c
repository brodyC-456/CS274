#include <stdio.h>
#include <math.h>

void hello(){
    puts("Hello!");
}

int adder(int x, int y){
    return x + y;
}

float quadratic_formula(float a, float b, float c){
    return (-b + sqrt((b*b) - (4 * a * c))) / (2 * a);
}

void print_num(char *s, int num){
    printf("%s: %d\n", s, num);
}

int main(){
    hello();

    printf("2 + 4 = %d\n", adder(2, 4));
    printf("2 - 4 = %d\n", adder(2, -4));

    printf("x^2 + 3x - 2.5 = 0 => x = %f\n", quadratic_formula(1.0, 3, -2.5));
    printf("3x^2 - 7.2x + 1 = 0 => x = %f\n", quadratic_formula(3, -7.2, 1));

    print_num("This is probably two", 2);
}
