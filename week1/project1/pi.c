#include <stdio.h>
#include <stdlib.h>

int usage(){
    puts("usage: pi iterations (<0)");
    return 1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        return usage();
    }

    int iterations = atoi(argv[1]);
    if(iterations < 1){
        return usage();
    }

    float denominator = 1;
    float appr = 0;
    for(int i = 1; i <= iterations; i++){
    
        if (i % 2 == 1){
            appr += 1/denominator;
        }
        else{
            appr -= 1/denominator;
        }

        denominator += 2;
        
    }
    float pi = appr * 4;
    printf("%f\n", pi);  
}