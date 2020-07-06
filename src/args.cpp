#include "args.h"
#include <cstring>

Args::Args(const std::string& input){
    std::string word = "";
    for (char c : input){
        if (c == ' ')
        {
            _arguments.push_back(word.c_str());
            word = "";
        }
        else
        {
            word = word + c;
        }
    }
    _arguments.push_back(word.c_str());
}


//void Args::addArgument(char* argument){
//    _arguments.insert(_arguments.end(), argument);
//}


const std::string& Args::operator[](size_t index){
    return _arguments[index];
}


void Args::remove(size_t index){
    _arguments.erase(_arguments.begin()+index);
}


size_t Args::size(){
    return _arguments.size();
}