#include <iostream>
#include "dna_terminal.h"
#include "../../../controller/command/i_command.h"
#include "args.h"
#include "../../write/include.h"

//try... catch...
DnaTerminal::DnaTerminal(DnaContainer* pDnaContainer):_pReader(new ConsoleReader("> cmd >>> ")), _pWriter(new ScreenWriter), _pDnaContainer(pDnaContainer), _hasDefaultReaderWriter(true), _commandFactory(
        CommandFactory::getInstance()){}

DnaTerminal::DnaTerminal(IReader* pReader, IWriter* pWriter, DnaContainer* pDnaContainer):_pReader(pReader), _pWriter(pWriter), _pDnaContainer(pDnaContainer), _hasDefaultReaderWriter(false), _commandFactory(
        CommandFactory::getInstance()){}

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
    if(!args.empty()){
        ICommand* command = _commandFactory->getCommand(args[0]);

        if(command){
            command->run(_pWriter, _pDnaContainer, args);
        }
        else{
            _pWriter->write("Invalid command");
        }
    }
}