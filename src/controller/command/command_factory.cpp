#include "command_factory.h"
#include "creation/all_commands.h"
#include "management/save_command.h"
#include <cstring>

CommandFactory* CommandFactory::_obj = NULL;


CommandFactory* CommandFactory::getInstance(){
    if(_obj == NULL){
        _obj = new CommandFactory();
    }

    return _obj;
}


void CommandFactory::resetInstance(){
    delete _obj;
    _obj = NULL;
}

CommandFactory::~CommandFactory(){
    std::map<std::string, ICommand*>::iterator it;

    for (it = _commandMap.begin(); it != _commandMap.end(); ++it)
    {
        delete it->second;
    }
}


CommandFactory::CommandFactory(){
    _commandMap.insert(std::pair<std::string, ICommand*>("new", new NewCommand));
    _commandMap.insert(std::pair<std::string, ICommand*>("load", new LoadCommand));
    _commandMap.insert(std::pair<std::string, ICommand*>("save", new SaveCommand));
    _commandMap.insert(std::pair<std::string, ICommand*>("dup", new DupCommand));
}


ICommand* CommandFactory::getCommand(const std::string& input){
    return _commandMap.find(input)->second;
}
