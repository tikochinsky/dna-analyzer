#include "args.h"

void Args::addArgument(char *argument){
    _arguments.insert(_arguments.end(), argument);
}


char* Args::operator[](size_t index){
    return _arguments[index];
}


void Args::remove(size_t index){
    _arguments.erase(_arguments.begin()+index);
}


size_t Args::size(){
    return _arguments.size();
}