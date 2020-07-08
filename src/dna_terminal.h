#ifndef DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#define DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#include "read_write/include.h"
#include "data/dna_container.h"

class DnaTerminal{
public:
    void run(IReader* pReader, IWriter* pWriter, DnaContainer& dnaContainer);

private:


    void runCommand(IReader* pReader, IWriter* pWriter, DnaContainer& dnaContainer);
};


#endif //DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
