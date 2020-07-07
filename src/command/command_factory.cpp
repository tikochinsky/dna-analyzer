#include "command_factory.h"
#include "creation/all_commands.h"
#include <cstring>


ICommand* CommandFactory::command(const char *input){
    if(!strcmp(input, "new")){
        return new NewCommand;
    }

    if(!strcmp(input, "load")){
        return new LoadCommand;
    }

    return NULL;
}
