#include "args.h"


Args::Args(const std::string& input){
    std::string word;
    for (size_t i = 0; i < input.size(); ++i){
        if (input[i] == ' ')
        {
            addArgument(word);
            word = "";
        }
        else
        {
            word += input[i];
        }
    }

    addArgument(word);
}


void Args::addArgument(const std::string& word){
    if(!word.empty()) {
        _arguments.push_back(word);
    }
}


const std::string& Args::operator[](size_t index)const{
    return _arguments[index];
}


size_t Args::size()const{
    return _arguments.size();
}


bool Args::empty(){
    return _arguments.empty();
}
