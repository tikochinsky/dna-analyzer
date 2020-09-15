#ifndef DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
#define DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H

#include "../view/UI/CLI/dna_terminal.h"

class DnaCommandManager{
public:
    DnaCommandManager();
//    DnaCommandManager(IReader* pReader, IWriter* pWriter);
    ~DnaCommandManager();
    void start();

    //how to send parameter?
    void setReader();
    void setWriter();

private:
    DnaContainer _dnaContainer;
    DnaTerminal* _dnaUI;
};


#endif //DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H