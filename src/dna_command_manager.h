#ifndef DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
#define DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H

#include "dna_terminal.h"

class DnaCommandManager{
public:
    DnaCommandManager();
    DnaCommandManager(IReader* pReader, IWriter* pWriter);
    ~DnaCommandManager();
    void start();

    //how to send parameter?
    void setReader();
    void setWriter();

private:
    DnaTerminal _dnaTerminal;
    DnaContainer _dnaContainer;
    IReader* _pReader;
    IWriter* _pWriter;
    bool _hasDefaultReaderWriter;
};


#endif //DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
