#include "dna_command_manager.h"
#include <iostream>


//try... catch...
DnaCommandManager::DnaCommandManager():_pReader(new ConsoleReader("> cmd >>> ")), _pWriter(new ScreenWriter), _hasDefaultReaderWriter(1){
    _dnaTerminal = new DnaTerminal(_pReader, _pWriter, &_dnaContainer);
}


DnaCommandManager::DnaCommandManager(IReader* pReader, IWriter* pWriter):_pReader(pReader), _pWriter(pWriter), _hasDefaultReaderWriter(0){
    _dnaTerminal = new DnaTerminal(_pReader, _pWriter, &_dnaContainer);
}


DnaCommandManager::~DnaCommandManager(){
    if(_hasDefaultReaderWriter){
        delete _pReader;
        delete _pWriter;
        delete _dnaTerminal;
    }

    else {
        delete _dnaTerminal;
    }
}

void DnaCommandManager::start(){
    _dnaTerminal->run();
}
