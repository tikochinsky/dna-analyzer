#include "args.h"


Args::Args(const std::string& input){
    init(input);
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


std::string Args::getName(){
    return "";
}


DnaMetaData* Args::getDna(){
    return NULL;
}


void Args::init(const std::string& input, DnaContainer* dnaContainer){
    std::string word;

    _arguments.clear();
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


bool Args::isName(const Args& args, size_t index){
    return args[index][0] == '@';
}


bool Args::isId(const Args& args, size_t index){
    return args[index][0] == '#';
}
