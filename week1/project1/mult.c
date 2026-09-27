#include <stdio.h>
#include <stdlib.h>

// I made it so you can do any size :)
#define SIZE 12


int main(void){
    for(int i = 1; i <= SIZE; i++){
        for(int j = 1; j <= SIZE; j++){
            printf("%4d", i * j);
        }
        puts("\n");
    }
}