#include <iostream>
#include <format>
#include <fstream>

void cat(char *filename){

    std::ifstream f(filename);
    if(!f.is_open()){
        std::cerr << "Error opening file\n";
    }

    std::string line;

    while (std::getline(f, line)){
        std::cout << std::format("{}\n", line);
    }
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        cat(argv[i]);
    }
}