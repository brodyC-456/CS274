#include <stdio.h>
#include <stdlib.h>

int usage(){
    puts("usage: sqrt number [iterations]");
    return 1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        return usage();
    }
    
    float n = atoi(argv[1]);
    int iterations = 20;
    if(argc == 3){
        iterations = atoi(argv[2]);
    }

    float sqrt = n / 2;
    for(int i = 0; i < iterations; i++){
        sqrt = 0.5 * (sqrt + n/sqrt);
    }

    printf("%f\n", sqrt);




}