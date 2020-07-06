#include "run_dna.h"
#include "dna_command_manager.h"
#include "read_write/include.h"

void RunDna::start(){
    DnaCommandManager manager;
    manager.start();
}
