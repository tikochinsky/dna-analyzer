#include <iostream>
#include "dna_terminal.h"
#include "command/command_factory.h"
#include "command/i_command.h"
#include "args.h"


DnaTerminal::DnaTerminal(IReader* pReader, IWriter* pWriter, DnaContainer* pDnaContainer):_pReader(pReader), _pWriter(pWriter), _pDnaContainer(pDnaContainer){}


void DnaTerminal::run(){
    while(1){
        runCommand();
    }
}


void DnaTerminal::runCommand(){
    Args args(_pReader->read());
    ICommand* command = CommandFactory::command(args[0].c_str());
    if(command){
        command->run(_pWriter, _pDnaContainer, args);
    }
    else{
        _pWriter->write("Invalid command");
    }
}