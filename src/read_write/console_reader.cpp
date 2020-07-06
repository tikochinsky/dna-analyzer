#include "console_reader.h"
#include <iostream>
#include <string>

ConsoleReader::ConsoleReader(const char *prompt):_prompt(prompt){}


const char* ConsoleReader::read(){
    std::string input;
    std::cout << _prompt;
    std::getline(std::cin, input);
    return input.c_str();
}