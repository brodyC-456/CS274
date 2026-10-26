#include <stdio.h>

void draw_box(int w, int h){
    for (int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            putchar('#');
        }
        putchar('\n');
    }
}

