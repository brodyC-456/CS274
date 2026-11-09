#pragma once
#include <string>


class StringPrinter {
    private:
        int strCount;
    public:
        StringPrinter(): strCount{0} {};
        int get_count() {return strCount;}
        void print_string(std::string);
};