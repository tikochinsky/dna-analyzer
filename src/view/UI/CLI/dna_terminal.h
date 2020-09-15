#ifndef DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#define DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
#include "../../read_write/include.h"
#include "../../../data/dna_container.h"
#include "../UI.h"


class DnaTerminal: public UI{
public:
    DnaTerminal(DnaContainer* pDnaContainer);
    DnaTerminal(IReader* pReader, IWriter* pWriter, DnaContainer* dnaContainer);
    ~DnaTerminal();
    void view();

private:
    IReader* _pReader;
    IWriter* _pWriter;
    DnaContainer* _pDnaContainer;
    bool _hasDefaultReaderWriter;
    void runCommand();
};


#endif //DNA_ANALYZER_PROJECT_DNA_TERMINAL_H
