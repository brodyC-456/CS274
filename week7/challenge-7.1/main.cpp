#include <iostream>
#include <string>
#include <format>

class StringPrinter {
    private:
        int strCount;
    public:
        StringPrinter(): strCount{0} {};
        int get_count() {return strCount;}
        void print_string(std::string);
};

void StringPrinter::print_string(std::string str){
    std::cout << str << '\n';
    strCount++;
}


int main(){
    StringPrinter p1;
    StringPrinter p2;

    p1.print_string("Hello from p1!");
    p1.print_string("This is a test from p1!");
    std::cout << std::format("p1's count: {}\n", p1.get_count());
    std::cout << std::format("p2's count: {}\n", p2.get_count());
    p2.print_string("And this is p2!");
    p2.print_string("And this is p2 printing more");
    p2.print_string("And this is p2 printing still more");
    std::cout << std::format("p1's count: {}\n", p1.get_count());
    std::cout << std::format("p2's count: {}\n", p2.get_count());


}