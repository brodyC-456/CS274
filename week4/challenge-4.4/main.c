#include <stdio.h>
#include <string.h>

#define NUM_LLMS 3

struct llm {
    char name[32];
    unsigned long long parameters;
    unsigned int context;
};

int main(){

    struct llm llms[NUM_LLMS] = {

        {
            .name = "Opus",
            .parameters = 700000000000,
            .context = 2000000
        },

        {
            .name = "Qwen",
            .parameters = 24000000000,
            .context = 262000
        },

        {
            .name = "Kimi",
            .parameters = 1000000000000,
            .context = 4000000
        }
    };

    for(int i = 0; i < NUM_LLMS; i++){
        printf("Model %s:\n \tparameters: %llu\n \tcontext: %u\n", llms[i].name, llms[i].parameters, llms[i].context);
    }
    
}