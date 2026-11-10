#include "cpu.h"
#include <iostream>
#include <format>

int usage(){
    std::cout << "usage: runprog filename" << '\n';
    return 1;
}


int main(int argc, char *argv[]){
    // check if theres an argument
    if(argc != 2){
        return usage();
    }

    // load cpu with instruction data
    CPU cpu1;
    cpu1.loader(argv[1]);

    // Run the instructions
    cpu1.runner();
}