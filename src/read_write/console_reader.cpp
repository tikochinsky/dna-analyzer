#include "console_reader.h"
#include <iostream>


ConsoleReader::ConsoleReader(const char *prompt):_prompt(prompt){}


const char* ConsoleReader::read(){
    std::cout << _prompt;
    std::getline(std::cin, _input);
    return _input.c_str();
}