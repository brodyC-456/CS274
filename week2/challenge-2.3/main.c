#include <stdio.h>

int array_sum(int nums[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += nums[i];
    }
    return sum;
}

int array_sum2(int nums[]){
    int sum = 0;
    for(int i = 0; nums[i] != 0; i++){
        sum += nums[i];
    }
    return sum;
}

void array_print(int nums[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    puts("");
}

void array_reverse(int nums[], int size){
    for(int i = 0; i < size / 2; i++){
        int temp = nums[i];
        nums[i] = nums[size - i - 1];
        nums[size - i - 1] = temp;
    }
}

int main(){
    int x[5] = {1,2,3,4,5};
    int y[6] = {5,6,7,8,9,0};
    int z[7] = {1,2,3,4,5,6,7};
    int w[8] = {2,4,6,8,10,12,14,16};

    printf("%d\n", array_sum(x, 5));
    printf("%d\n", array_sum2(y));
    array_reverse(z, 7);
    array_reverse(w, 8);
    array_print(z, 7);
    array_print(w, 8);

}