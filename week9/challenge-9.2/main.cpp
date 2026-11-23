#include "holder.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <format>

int usage(){
    std::cout << "usage: main index\n";
    return 1;
}

int main(int argc, char *argv[]){

    Holder h1;

    if(argc < 2){
        return usage();
    }
    int index = 0;
    try{
        index = std::stoi(argv[1]);
    }
    catch(const std::invalid_argument &e){
        std::cout << "Error invalid argument: " << e.what() << '\n';
    }
    catch(const std::out_of_range &e){
        std::cout << "Error out of range: " << e.what() << '\n';
    }

    try{
        std::cout << std::format("the value at {} is {}\n", index, h1.get(index));
    }
    catch(const std::out_of_range &e){
        std::cout << "Error out of range: " << e.what() << '\n';
    }
}