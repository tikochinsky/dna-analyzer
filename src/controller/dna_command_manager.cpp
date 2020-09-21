#include "dna_command_manager.h"
#include "../view/UI/CLI/dna_terminal.h"


DnaCommandManager::DnaCommandManager():_dnaUI(NULL){
    _dnaUI = new DnaTerminal(&_dnaContainer);
}


DnaCommandManager::~DnaCommandManager(){
    delete _dnaUI;
}

void DnaCommandManager::start(){
    _dnaUI->view();
}
