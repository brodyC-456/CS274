#include "cpu.h"
#include <iostream>
#include <format>
#include <fstream>
#include <string>
#include <unordered_map>

/**
 * Loads program data into a shared CPU memory array
 */

void CPU::loader(char *filename){
    
    // load file and ensure it works
    std::ifstream f(filename);

    if (!f.is_open()) {
        std::cerr << "Error: Could not open the file!" << '\n';
        return;
    }

    
    std::string line;
    int inst_index = 0;

    // This maps strings we will find in the file to their correct enum values
    // Avoids a large if/else or switch block
    std::unordered_map<std::string, Operations> ops = {
        {"PUSH", PUSH},
        {"POP", POP},
        {"DUP", DUP},
        {"ADD", ADD},
        {"SUB", SUB},
        {"JZ", JZ},
        {"JNZ", JNZ},
        {"PRT", PRT},
        {"END", END}
    };
    
    // Loop through lines of the file
    while (std::getline(f, line)) {
        // if its an instruction, we add the enum value to the memory array
        if(ops.contains(line)) {
            instructions[inst_index] = ops.at(line);
        }
        // if its a number, we just add the value to the memory array
        else{
            instructions[inst_index] = std::stoi(line);
        }
        inst_index++;
    }
}

/**
 * Executes a set of instructions using the shared memory array and a stack
 */

void CPU::runner(){
    while(instructions[pc] != END){
        // Each operation has a different implementation, they're all in this switch
        switch (instructions[pc]){
            case PUSH: {
                s.push(instructions[pc + 1]);
                pc += 2;
                break;
            }
            case POP: {
                s.pop();
                pc++;
                break;
            }
            case DUP: {
                s.push(s.peek());
                pc++;
                break;
            }
            case ADD: {
                int i1 = s.pop();
                int i2 = s.pop();
                s.push(i1 + i2);
                pc++;
                break;
            }
            case SUB: {
                int i1 = s.pop();
                int i2 = s.pop();
                s.push(i2 - i1);
                pc++;
                break;
            }
            case JZ: {
                int top = s.pop();
                if(top == 0){
                    pc = instructions[pc + 1];
                }
                else{
                    pc += 2;
                }
                break;
            }
            case JNZ: {
                int top = s.pop();
                if(top != 0){
                    pc = instructions[pc + 1];
                }
                else{
                    pc += 2;
                }
                break;
            }
            case PRT: {
                std::cout << std::format("{}\n", s.peek());
                pc++;
                break; 
            }  
        }
    }
}