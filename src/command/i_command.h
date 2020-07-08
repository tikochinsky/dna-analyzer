#ifndef DNA_ANALYZER_PROJECT_ICOMMAND_H
#define DNA_ANALYZER_PROJECT_ICOMMAND_H

#include "../data/dna_container.h"
#include "../args.h"


class ICommand{
public:
    virtual ~ICommand(){}
    virtual void run(IWriter* writer, DnaContainer* dnaContainer, const Args& args)=0;

protected:
    virtual void print(IWriter* writer, const DnaMetaData& dna)=0;
};

#endif //DNA_ANALYZER_PROJECT_ICOMMAND_H
