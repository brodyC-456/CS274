#include <stdio.h>
#include <string.h>

struct llm {
    char name[32];
    unsigned long long parameters;
    unsigned int context;
};

int main(){
    struct llm opus = {
        .name = "Opus",
        .parameters = 700000000000,
        .context = 2000000
    };

    struct llm qwen = {
        .name = "Qwen",
        .parameters = 24000000000,
        .context = 262000
    };

    struct llm kimi = {
        .name = "Kimi",
        .parameters = 1000000000000,
        .context = 4000000
    };


    printf("Model %s:\n \tparameters: %llu\n \tcontext: %u\n", opus.name, opus.parameters, opus.context);
    printf("Model %s:\n \tparameters: %llu\n \tcontext: %u\n", qwen.name, qwen.parameters, qwen.context);
    printf("Model %s:\n \tparameters: %llu\n \tcontext: %u\n", kimi.name, kimi.parameters, kimi.context);
}