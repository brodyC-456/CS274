#include <iostream>
#include <format>
#include "stack.h"

int main(){
    Stack s1;
    s1.push(1);
    std::cout << "pushed 1" << '\n';
    s1.push(122);
    std::cout << "pushed 122" << '\n';
    std::cout << std::format("popped {}\n", s1.pop());
    std::cout << std::format("top element: {}\n", s1.peek());

}
