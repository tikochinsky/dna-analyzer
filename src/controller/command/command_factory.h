#ifndef DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H
#define DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H

#include "i_command.h"

class CommandFactory{
public:
    static ICommand* command(const char *input);
};


#endif //DNA_ANALYZER_PROJECT_COMMAND_FACTORY_H
