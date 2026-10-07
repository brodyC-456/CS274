#include <stdio.h>

void print_char(char alph[], int i){
    printf("%c\n", alph[i]);
}

void print_char_num(char alph[], int i){
    printf("%d\n", alph[i]);
}

void print_str(char chars[]){

    for(int i = 0; chars[i] != '\0'; i++){
        putchar(chars[i]);
    }
}

int length_str(char chars[]){
    int len = 0;
    for(int i = 0; chars[i] != '\0'; i++){
        len++;
    }
    return len;
}

void alpha_index(char chars[]){
    printf("Letter indexes of %s:\n", chars);
    for(int i = 0; chars[i] != '\0'; i++){
        printf("%d\n", chars[i] - 'A');
    }
}

int main(){
    char alph[] = "ABCD\n";
    print_char(alph, 0);
    print_char(alph, 1);
    print_char(alph, 2);
    print_char_num(alph, 0);
    print_char_num(alph, 1);
    print_char_num(alph, 2);
    print_char_num(alph, 4);
    print_char_num(alph, 5);
    print_str(alph);
    printf("%d\n", length_str(alph));
    alpha_index("WOMBAT");
}