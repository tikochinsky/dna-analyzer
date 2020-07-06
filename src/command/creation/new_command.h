#ifndef DNA_ANALYZER_PROJECT_NEW_H
#define DNA_ANALYZER_PROJECT_NEW_H

#include "../i_command.h"

class NewCommand:public ICommand{
public:
    virtual void run(IWriter* writer, DnaContainer& dnaContainer, Args args);
    virtual void print(IWriter* writer, const DnaMetaData& dna);
};


#endif //DNA_ANALYZER_PROJECT_NEW_H
