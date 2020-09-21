#ifndef DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
#define DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H

#include "../view/UI/UI.h"
#include "../data/dna_container.h"

class DnaCommandManager{
public:
    DnaCommandManager();
    ~DnaCommandManager();
    void start();

private:
    DnaContainer _dnaContainer;
    UI* _dnaUI;
};


#endif //DNA_ANALYZER_PROJECT_DNA_COMMAND_MANAGER_H
