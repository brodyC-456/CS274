#include "mather.h"
#include "boxer.h"
#include <stdio.h>

int main(void){
    printf("2 + 2 = %d\n", add(2, 2));
    printf("4 - 2 = %d\n", sub(4, 2));
    puts("3x5 rectangle:\n");
    draw_box(3, 5);
}