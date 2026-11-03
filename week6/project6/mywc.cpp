#include <cctype>
#include <iostream>
#include <fstream>
#include <format>

// State machine for reading the lines
enum Line_State {
    at_start_of_line,
    in_spaces,
    in_non_spaces
};


int usage(){
    std::cout << "usage: mywc filename\n";
    return 1;
}

/**
 * Takes a line in the file as an argument and returns the number of words in it
 * Loops through every character in the line and decides how to proceed based on its reading state
 */
int count_words_on_line(std::string line){
    int line_wc = 0;
    // Initialize state to be at the start of the line
    Line_State line_state = at_start_of_line;

    // Loop through each character
    for(char c : line){
        // Check if we're on a space
        int is_space = std::isspace(c);
        switch (line_state){
            // If we're at the start of the line, set the new state and increment counter if the first character is a letter
            case at_start_of_line:
                if(is_space){
                    line_state = in_spaces;
                }
                else{
                    line_wc++;
                    line_state = in_non_spaces;
                }
                break;
            case in_spaces:
                // If we find a letter, set the new state and increment the word count
                if(!is_space){
                    line_wc++;
                    line_state = in_non_spaces;
                }
                // If it's another space, we do nothing and continue
                break;
            case in_non_spaces:
                // If we find a space, change the state
                if(is_space){
                    line_state = in_spaces;
                }
                // If it's another letter, continue
                break;
            // We should never get here
            default:
                std::cerr << "Error: invalid line";
                return -1;
        }
    }

    return line_wc;

}


int main(int argc, char *argv[]){
    // Only takes one file as an argument
    if(argc != 2){
        return usage(); 
    }

    // Open the file stream
    std::ifstream f(argv[1]);
    if(!f.is_open()){
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Loop through each line, adding their word counts to the total word count
    std::string line;
    int wc = 0;
    while (std::getline(f, line)){
        wc += count_words_on_line(line);
    }
    // Print word count
    std::cout << std::format("{}\n", wc);

}