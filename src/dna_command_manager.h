#ifndef DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
#define DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H

#include "read_write/include.h"
#include "data/dna_container.h"
#include "args.h"

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
    DnaContainer _dnaContainer;
    IReader* _pReader;
    IWriter* _pWriter;
    bool _hasDefaultReaderWriter;

    void runCommand();
};


#endif //DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
