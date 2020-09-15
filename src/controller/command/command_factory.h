#ifndef DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H
#define DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H

#include "i_command.h"


class CommandFactory{
public:
    static CommandFactory* getCommandFactory();
    ICommand* getCommand(const std::string& input);

    ~CommandFactory();

private:
    CommandFactory();
    static CommandFactory* _obj;

    std::map<std::string, ICommand*> _commandMap;
};


//
//class CommandFactory{
//public:
//    static ICommand* command(const char *input);
//};


#endif //DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H
