#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int usage(){
    puts("usage: rpncalc [digits], [* | + | / | -]");
    return 1;
}

int is_operator(char *token){
    if((*token == '+' || *token == '-' || *token == '*' || *token =='/') && strlen(token) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[]){
    if(argc < 1){
        return usage();
    }

    struct stack *s = {
        .top = NULL
    };

    for(int i = 0; i < argc - 1; i++){
        char *token = argv[i];
        if(is_operator(token)){
            float f1 = pop(s);
            float f2 = pop(s);
            if(isnan(f1) || isnan(f2)){
                printf("rpncalc: missing operand for '%c'\n", *token);
                exit(1);
            }

            if(*token == '+'){
                push(s, f1 + f2);
            }
            if(*token == '-'){
                push(s, f1 - f2);
            }
            if(*token == '*'){
                push(s, f1 * f2);
            }
            if(*token == '/'){
                if(f2 == 0){
                    puts("rpncalc: devision by zero");
                    exit(1);
                }
                push(s, f1 / f2);
            }
        }
        else{
            float f;
            char *badchar;

            f = strtof(*token, &badchar);

            if (*badchar != '\0') {
                printf("rpncalc: error: %c\n", *badchar); 
                exit(1);
            } 
            else {
                push(s, atof(*token));
            }
        }
    }

    float final = pop(s);
    if(!isnan(pop(s))){
        puts("rpncalc: warning: extra items remaining on stack");
    }
    printf("%f\n", final);


}