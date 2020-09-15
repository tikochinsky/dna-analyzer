#include <iostream>
#include "dna_terminal.h"
#include "../../../controller/command/command_factory.h"
#include "../../../controller/command/i_command.h"
#include "args.h"


DnaTerminal::DnaTerminal(DnaContainer* pDnaContainer):_pReader(new ConsoleReader("> cmd >>> ")), _pWriter(new ScreenWriter), _pDnaContainer(pDnaContainer), _hasDefaultReaderWriter(true){}

DnaTerminal::DnaTerminal(IReader* pReader, IWriter* pWriter, DnaContainer* pDnaContainer):_pReader(pReader), _pWriter(pWriter), _pDnaContainer(pDnaContainer), _hasDefaultReaderWriter(false){}

DnaTerminal::~DnaTerminal(){
    if(_hasDefaultReaderWriter){
        delete _pReader;
        delete _pWriter;
    }
}

void DnaTerminal::view(){
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

//    !!delete command;
}