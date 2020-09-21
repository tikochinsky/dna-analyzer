#include "run_dna.h"
#include "dna_command_manager.h"
#include "command/command_factory.h"


void RunDna::start(){
    DnaCommandManager manager;
    manager.start();
    shutDown();
}


void RunDna::shutDown(){
    CommandFactory::resetInstance();
}