#include "dna_command_manager.h"
#include "command/command_factory.h"
#include "command/i_command.h"
#include <iostream>
#include <cstring>
#include <sstream>


//try... catch...
DnaCommandManager::DnaCommandManager():_pReader(new ConsoleReader("> cmd >>> ")), _pWriter(new ScreenWriter), _hasDefaultReaderWriter(1){}


DnaCommandManager::DnaCommandManager(IReader* pReader, IWriter* pWriter):_pReader(pReader), _pWriter(pWriter), _hasDefaultReaderWriter(0){}


DnaCommandManager::~DnaCommandManager(){
    if(_hasDefaultReaderWriter){
        delete _pReader;
        delete _pWriter;
    }
}

void DnaCommandManager::start(){
    while(1){
        runCommand();
    }
}


void DnaCommandManager::runCommand(){
    Args args(_pReader->read());
    ICommand* command = CommandFactory::command(args[0].c_str());
    if(command){
        command->run(_pWriter,_dnaContainer, args);
    }
}
