#include <stdio.h>
#include <stdlib.h>

int main(void){
    for(int i = 0; i < 10; i++){
        printf("%d ", i);
    }
    puts("");
    for(int i = 0; i < 10; i += 2){
        printf("%d ", i);
    }
    puts("");
    for(int i = 9; i >= 0; i--){
        printf("%d ", i);
    }
    puts("");
    for (int i = 20; i >= 0; i -= 4){
        printf("%d ", i);
    }
    puts("");
}