#include "args.h"


Args::Args(const std::string& input){
    std::string word;
    for (size_t i = 0; i < input.size(); ++i){
        if (input[i] == ' ')
        {
            _arguments.push_back(word);
            word = "";
        }
        else
        {
            word += input[i];
        }
    }
    _arguments.push_back(word);
}


const std::string& Args::operator[](size_t index)const{
    return _arguments[index];
}


size_t Args::size()const{
    return _arguments.size();
}