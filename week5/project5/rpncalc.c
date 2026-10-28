#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int usage(){
    puts("usage: rpncalc [digits], [* | + | / | -]");
    return 1;
}

/**
 * Returns true if a character is a mathematical operator
 */

int is_operator(char *token){
    if((*token == '+' || *token == '-' || *token == '*' || *token =='/') && strlen(token) == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char *argv[]){
    // No arguments
    if(argc == 1){
        return usage();
    }

    // Initialize a stack
    struct stack *s = malloc(sizeof(*s));
    s->top = NULL;

    // For each token
    for(int i = 1; i < argc; i++){
        // Store the token
        char *token = argv[i];
        // Check if its an operator
        if(is_operator(token)){
            // Pop the last two operands
            float f1 = pop(s);
            float f2 = pop(s);
            // If theres not enough operands, exit with an error
            if(isnan(f1) || isnan(f2)){
                printf("rpncalc: missing operand for '%c'\n", *token);
                exit(1);
            }
            // Do the appropriate operations
            if(*token == '+'){
                push(s, f1 + f2);
            }
            if(*token == '-'){
                push(s, f2 - f1);
            }
            if(*token == '*'){
                push(s, f1 * f2);
            }
            if(*token == '/'){
                // Check for devision by 0
                if(f1 == 0){
                    puts("rpncalc: devision by zero");
                    exit(1);
                }
                push(s, f2 / f1);
            }
        }
        // Gets here if the token is a number
        else{
            float f;
            char *badchar;
            // Check if its a valid float
            f = strtof(token, &badchar);
            // This means we have an invalid float, exit with an error
            if (*badchar != '\0') {
                printf("rpncalc: error: %s\n", badchar); 
                exit(1);
            } 
            // If we do have a valid float, push it to the stack
            else {
                push(s, f);
            }
        }
    }

    // Grab the result
    float final = pop(s);
    // Do one more pop and see if theres anything left on the stack
    float last_pop = pop(s);
    if(!isnan(last_pop)){
        // Warning if there's items left on the stack
        puts("rpncalc: warning: extra items remaining on stack");
    }
    // Print our final result and free the stack
    printf("%f\n", final);
    free(s);

}