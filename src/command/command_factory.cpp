#include "command_factory.h"
#include "creation/new_command.h"
#include <cstring>


ICommand* CommandFactory::command(const char *input){

        if(!strcmp(input, "new"))
            return new NewCommand;
}
