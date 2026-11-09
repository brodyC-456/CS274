#include <iostream>
#include <format>
#include "stack.h"

enum Days {
    MONDAY = 10,
    TUESDAY,
    WEDNESDAY
};

enum class Months {
    January,
    February,
    March,
    April,
    May
};

int main(){
    enum Days days = MONDAY;
    Months month = Months::January;
    Stack s1;
    s1.push(days);
    days = TUESDAY;
    s1.push(days);
    std::cout << std::format("popped {}\n", s1.pop());
    std::cout << std::format("popped {}\n", s1.pop());
    s1.push(static_cast<int>(month));
    month = Months::April;
    s1.push(static_cast<int>(month));
    std::cout << std::format("popped {}\n", s1.pop());
    std::cout << std::format("popped {}\n", s1.pop());
}
