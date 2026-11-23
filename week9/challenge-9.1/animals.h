#pragma once

#include <iostream>

class Animal {
    public:
        virtual ~Animal() = default;
        virtual void sound() { std::cout << "Generic animal sound\n"; }
};

class Cat : public Animal {
    public:
        void sound() override { std::cout << "Meow\n"; }
    };

class Dog : public Animal {
    public:
        void sound() override { std::cout << "Arf!\n"; }
    };