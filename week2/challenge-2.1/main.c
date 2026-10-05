#include <stdio.h>

#define ARRAY_SIZE 15
int main(){
    int nums[ARRAY_SIZE];

    for(int i = ARRAY_SIZE - 1, val = 0; i >= 0; i--, val += 10){
        nums[i] = val;
        printf("a[%d] = %d\n", i, nums[i]);
    }
}