#include "dna_command_manager.h"
#include <iostream>


//try... catch...
DnaCommandManager::DnaCommandManager():_dnaUI(NULL){
    _dnaUI = new DnaTerminal(&_dnaContainer);
}

//
//DnaCommandManager::DnaCommandManager(IReader* pReader, IWriter* pWriter):
//_pReader(pReader), _pWriter(pWriter), _hasDefaultReaderWriter(false){
//    _dnaUI = new DnaTerminal(_pReader, _pWriter, &_dnaContainer);
//}


DnaCommandManager::~DnaCommandManager(){
    delete _dnaUI;
}

void DnaCommandManager::start(){
    _dnaUI->view();
}
