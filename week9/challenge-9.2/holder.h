#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>

class Holder {
    private:
        int nums[50];
    public:
        Holder() {for(int i = 0; i < 50; i++){nums[i] = i * 10;}}
        int get(int i){if(i > 49 || i < 0){throw std::out_of_range("index out of range!");} else{return nums[i];}}
};