#include "dna_command_manager.h"
#include "command/command_factory.h"
#include "command/i_command.h"
#include <iostream>
#include <cstring>
#include <sstream>


//try... catch...
DnaCommandManager::DnaCommandManager():_pReader(new ConsoleReader("> cmd >>> ")), _pWriter(new ScreenWriter){}


void DnaCommandManager::start(){
    while(1){
        runCommand();
    }
}


//void DnaCommandManager::runCommand(){
//    Args args = promptAndInput();
//    ICommand* command = CommandFactory::command(args[0].c_str());
//    args.remove(0);
//    command->run(_dnaContainer, args);
//}


void DnaCommandManager::runCommand(){
    Args args(_pReader->read());
    ICommand* command = CommandFactory::command(args[0].c_str());
    args.remove(0);
    command->run(_pWriter,_dnaContainer, args);
}

Args DnaCommandManager::promptAndInput(){
    std::string input;

    std::cout << "> cmd >>> ";

    std::getline(std::cin, input);
    Args args(input);

    return args;
}
