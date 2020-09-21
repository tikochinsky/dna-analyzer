#ifndef DNA_ANALYZER_PROJECT_SAVE_COMMAND_H
#define DNA_ANALYZER_PROJECT_SAVE_COMMAND_H

#include "../i_command.h"

class SaveCommand:public ICommand{
public:
    virtual void run(IWriter* writer, DnaContainer* dnaContainer, const Args& args);

protected:
    virtual void print(IWriter* writer, const DnaMetaData& dna);

private:
    static void saveSeqById(IWriter* writer, DnaContainer* dnaContainer, const Args& args);
    static void saveSeqByName(IWriter* writer, DnaContainer* dnaContainer, const Args& args);
    bool hasValidNumOfArgs(const Args& args);

    static std::string _rootDir;
};




#endif //DNA_ANALYZER_PROJECT_SAVE_COMMAND_H
