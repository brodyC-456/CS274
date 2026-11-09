#pragma once

class Stack {
     private:
        int current_index;
        int stack[128];
    public:
        Stack(): current_index{0}{};
        void push(int num){stack[current_index++] = num;}
        int pop(){return stack[--current_index];}
        int peek(){return stack[current_index - 1];}
};