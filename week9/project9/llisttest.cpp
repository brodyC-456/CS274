#include "llist.h"
#include <iostream>
#include <string>

int usage(){
    std::cout << "usage: command [args]\n";
    return 1;
}

int main(int argc, char *argv[]){
    if(argc < 2){
        return usage();
    }

    LinkedList l;

    for(int i = 1; i < argc; ){
        std::string arg{argv[i]};

        if(arg == "push"){
            l.push(std::stoi(argv[i + 1]));
            i += 2;
        }
        else if(arg == "pop"){
           l.pop();
           i++;
        }
        else if(arg == "pushback"){
            l.pushback(std::stoi(argv[i + 1]));
            i+=2;
        }
        else if(arg=="popback"){
            l.popback();
            i++;
        }
        else if(arg=="delete"){
            l.del(std::stoi(argv[i + 1]));
            i+=2;
        }
        else if(arg=="print"){
            l.print();
            i++;
        }
        else{
            std::cout << "invalid argument: " << arg << '\n';
            return 1;
        }
    }
    
}