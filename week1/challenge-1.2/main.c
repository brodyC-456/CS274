#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i0 = atoi(argv[1]);
    int i1 = atoi(argv[2]);
    (void)argc;

    if(i0 == i1){
        printf("%d == %d\n", i0, i1);
    }
    else if(i0 < i1){
        printf("%d < %d\n", i0, i1);
    }
    else{
        printf("%d > %d\n", i0, i1);
    }

}