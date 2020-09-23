//
// Created by a on 9/22/20.
//

#include "args_factory.h"

#include "creation/all_args.h"
#include "management/all_args.h"
#include <cstring>

ArgsFactory* ArgsFactory::_obj = NULL;


ArgsFactory* ArgsFactory::getInstance(){
    if(_obj == NULL){
        _obj = new ArgsFactory();
    }

    return _obj;
}


void ArgsFactory::resetInstance(){
    delete _obj;
    _obj = NULL;
}


// register myself
ArgsFactory::ArgsFactory(){
    _argsMap.insert(std::pair<std::string, SharedPtr<IArgs> >("new", SharedPtr<IArgs>(new NewArgs(""))));
    _argsMap.insert(std::pair<std::string, SharedPtr<IArgs> >("load", SharedPtr<IArgs>(new LoadArgs(""))));
    _argsMap.insert(std::pair<std::string, SharedPtr<IArgs> >("save", SharedPtr<IArgs>(new SaveArgs(""))));
    _argsMap.insert(std::pair<std::string, SharedPtr<IArgs> >("dup", SharedPtr<IArgs>(new DupArgs(""))));
}


SharedPtr<IArgs> ArgsFactory::getArgs(const std::string& input){
    return _argsMap.find(input)->second;
}
