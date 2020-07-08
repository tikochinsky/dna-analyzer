#include <iostream>
#include "dna_terminal.h"
#include "command/command_factory.h"
#include "command/i_command.h"
#include "args.h"


void DnaTerminal::run(IReader* pReader, IWriter* pWriter, DnaContainer& dnaContainer){
    while(1){
        runCommand(pReader, pWriter, dnaContainer);
    }
}


void DnaTerminal::runCommand(IReader* pReader, IWriter* pWriter, DnaContainer& dnaContainer){
    Args args(pReader->read());
    ICommand* command = CommandFactory::command(args[0].c_str());
    if(command){
        command->run(pWriter, dnaContainer, args);
    }
    else{
        pWriter->write("Invalid command");
    }
}