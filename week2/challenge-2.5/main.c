#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[]){
    
    int caps = 0;
    int lowers = 0;
    int alphas = 0;
    int nums = 0;
    int punc = 0;

    for(int i = 0; argv[1][i] != '\0'; i++){
        char c = argv[1][i];
        if(isupper(c)){
            caps++;
        }
        if(islower(c)){
            lowers++;
        }
        if(isalpha(c)){
            alphas++;
        }
        if(isdigit(c)){
            nums++;
        }
        if(ispunct(c)){
            punc++;;
        }
    }

    printf("Capitals: %d\n", caps);
    printf("Lowercase: %d\n", lowers);
    printf("Alphabetic: %d\n", alphas);
    printf("Numeric: %d\n", nums);
    printf("Punctuation: %d\n", punc);
}