#include <iostream>
#include <format>


class MyData {
    private:
        int *data;

    public:
        MyData(int size): data{new int[size]} {std::cout << std::format("=== CTOR: size {}\n", size);}
        int& at(int i){return data[i];}
        ~MyData(){delete[] data; std::cout << "=== DTOR\n";}

};


int main(){
    MyData md(5);
    md.at(3) = 999;
    std::cout << md.at(3) << '\n';  // prints 999

    MyData md2 = md;

}


/**
 * What's the output?
 *      "free(): double free detected in tcache 2
 *       Aborted (core dumped)"
 * How does it compare to what you'd hope would be there?
 *      I would have hoped for a successful constructor message ( === CTOR size 5)
 * What's happening under the hood?
 *      The first object creates an array of int pointers, and when you assign it to a new object, it just steals that array.
 *      When both of the objects fall out of scope, the first destructor frees the data.
 *      The second constructor then tries to free that same data thats already been freed, resulting in a double free.
 */