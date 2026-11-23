#include <vector>
#include "animals.h"


int main(){
    Animal a;
    Cat c;
    Dog d;

    std::vector<Animal> v1;
    v1.push_back(a);
    v1.push_back(c);
    v1.push_back(d);

    for(Animal animal : v1){
        animal.sound();
    }

    std::vector<Animal*> v2;
    v2.push_back(&a);
    v2.push_back(&c);
    v2.push_back(&d);

    for(Animal *animal : v2){
        animal->sound();
    }

}