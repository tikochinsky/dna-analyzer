#include "dna_command_manager.h"
#include "command/command_factory.h"
#include "command/i_command.h"
#include <iostream>
#include <cstring>


//try... catch...
DnaCommandManager::DnaCommandManager():_pReader(new RawdnaFileReader), _pWriter(new RawdnaFileWriter){}


void DnaCommandManager::start(){
    while(1){
        runCommand();
    }
}


void DnaCommandManager::runCommand(){
    Args args = promptAndInput();
    ICommand* command = CommandFactory::command(args[0]);
    args.remove(0);
    command->run(_dnaContainer, args);
}


Args DnaCommandManager::promptAndInput(){
    char* input;
    Args args;

    std::cout << "> cmd >>> ";
    std::cin >> input;
    strtok(input, " ");

    while (input != NULL)
    {
        args.addArgument(strtok (NULL, " "));
    }
    return args;
}
