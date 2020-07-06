#ifndef DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
#define DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H

#include "read_write/include.h"
#include "data/dna_container.h"
#include "args.h"

class DnaCommandManager{
public:
    DnaCommandManager();
    void start();

    //how to send parameter?
    void setReader();
    void setWriter();

private:
    DnaContainer _dnaContainer;
    IReader* _pReader;
    IWriter* _pWriter;

    void runCommand();
    Args promptAndInput();
};


#endif //DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
