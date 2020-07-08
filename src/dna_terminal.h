#ifndef DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#define DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#include "read_write/include.h"
#include "data/dna_container.h"

class DnaTerminal{
public:
    DnaTerminal(IReader* pReader, IWriter* pWriter, DnaContainer* dnaContainer);
    void run();

private:
    IReader* _pReader;
    IWriter* _pWriter;
    DnaContainer* _pDnaContainer;

    void runCommand();
};


#endif //DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
