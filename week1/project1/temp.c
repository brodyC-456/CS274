#include <stdio.h>
#include <stdlib.h>

int usage(){
    puts("usage: temp value");
    return 1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        return usage();
        
    }
    float value = strtof(argv[1], NULL);
    float c = (value - 32) * 5/9;
    float f = (value * 9/5) + 32;

    printf("%f F is %f C\n", value, c);
    printf("%f C is %f F\n", value, f);
    
    
    return 0;
}