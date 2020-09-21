//
// Created by a on 9/16/20.
//

#ifndef DNA_ANALYZER_PROJECT_DUP_COMMAND_H
#define DNA_ANALYZER_PROJECT_DUP_COMMAND_H
#include "../i_command.h"


class DupCommand: public ICommand{
public:
    virtual void run(IWriter* writer, DnaContainer* dnaContainer, const Args& args);

protected:
    virtual void print(IWriter* writer, const DnaMetaData& dna);

private:
    static const DnaMetaData* getDnaToDup(IWriter* writer, DnaContainer* dnaContainer, const Args& args);
    static std::string extractName(IWriter* writer, DnaContainer* dnaContainer, const DnaMetaData* dnaToDup, const Args& args);

    static bool hasValidNumOfArgs(const Args& args);
};


#endif //DNA_ANALYZER_PROJECT_DUP_COMMAND_H
