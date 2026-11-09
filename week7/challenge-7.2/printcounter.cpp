#include "printcounter.h"
#include <iostream>

void StringPrinter::print_string(std::string str){
    std::cout << str << '\n';
    strCount++;
}
