#include <iostream>
#include <format>
#include <fstream>

int main(){
    std::ofstream outfile("foo.txt");

    for(int i = 1; i < 11; i++){
        outfile << std::format("Line {}/10\n", i);
    }
    
    outfile.close();
}