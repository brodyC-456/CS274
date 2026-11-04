#include <string>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]){
    if(argc < 2){
        std::cout << "usage: main [words]" << "\n";
        return 1;
    }

    for(int i = argc - 1; i > 0; i--){\
        std::string s = argv[i];
        std::reverse(s.begin(), s.end());
        std::cout << s << " ";
    }
    std::cout << "\n";
}