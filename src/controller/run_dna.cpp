#include "run_dna.h"
#include "dna_command_manager.h"


void RunDna::start(){
    DnaCommandManager manager;
    manager.start();
}