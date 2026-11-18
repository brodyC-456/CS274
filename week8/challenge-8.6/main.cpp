#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void sound() { std::cout << "Generic animal sound\n";}
};

class Dog : public Animal {
    public:
        void sound() override {std::cout << "woof\n";}
};

class Cat : public Animal {
    public:
        void sound() override {std::cout << "meow\n";}
};

void make_sound(Animal &a)
{
    a.sound();
}

int main()
{
    Animal a;
    Dog b;
    Cat c;

    make_sound(a);
    make_sound(b);
    make_sound(c);
}

// Broken code

// #include <iostream>

// class Animal {
// public:
//     ~Animal() = default;
//     void sound() { std::cout << "Generic animal sound\n";}
// };

// class Dog : public Animal {
//     public:
//         void sound() {std::cout << "woof\n";}
// };

// class Cat : public Animal {
//     public:
//         void sound() {std::cout << "meow\n";}
// };

// void make_sound(Animal &a)
// {
//     a.sound();
// }

// int main()
// {
//     Animal a;
//     Dog b;
//     Cat c;

//     make_sound(a);
//     make_sound(b);
//     make_sound(c);
// }