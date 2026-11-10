#pragma once
#include "stack.h"

// contains all possible cpu operations
enum Operations {
    PUSH,
    POP,
    DUP,
    ADD,
    SUB,
    JZ,
    JNZ,
    PRT,
    END
};

class CPU {
    private:
        int instructions[1024];
        Stack s;
        int pc;
    public:
        // initialize program counter to 0
        CPU(): pc{0} {};
        // int* get_instructions() {return instructions;} (needed this for testing)
        void loader(char *filename);
        void runner();
};