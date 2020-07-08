#ifndef DNA_ANALYZER_PROJECT_SAVE_COMMAND_H
#define DNA_ANALYZER_PROJECT_SAVE_COMMAND_H

#include "../i_command.h"

class SaveCommand:public ICommand{
public:
    virtual void run(IWriter* writer, DnaContainer* dnaContainer, const Args& args);

protected:
    virtual void print(IWriter* writer, const DnaMetaData& dna);

private:
    void saveSeqById(IWriter* writer, DnaContainer* dnaContainer, const Args& args);
    void saveSeqByName(IWriter* writer, DnaContainer* dnaContainer, const Args& args);
};




#endif //DNA_ANALYZER_PROJECT_SAVE_COMMAND_H
