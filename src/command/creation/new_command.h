#ifndef DNA_ANALYZER_PROJECT_NEW_H
#define DNA_ANALYZER_PROJECT_NEW_H

#include "../i_command.h"

class NewCommand:public ICommand{
public:
    void run(DnaContainer& dnaContainer, Args args);
    void print(const DnaMetaData& dna);
};


#endif //DNA_ANALYZER_PROJECT_NEW_H
