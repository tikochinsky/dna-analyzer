#ifndef DNA_ANALYZER_PROJECT_LOAD_COMMAND_H
#define DNA_ANALYZER_PROJECT_LOAD_COMMAND_H

#include "../i_command.h"

class LoadCommand:public ICommand{
public:
    virtual void run(IWriter* writer, DnaContainer* dnaContainer, const Args& args);

protected:
    virtual void print(IWriter* writer, const DnaMetaData& dna);

private:
    std::string extractName(IWriter* writer,  DnaContainer* dnaContainer, const Args& args);
    static bool hasValidNumOfArgs(const Args& args);

    static std::string _rootDir;
};


#endif //DNA_ANALYZER_PROJECT_LOAD_COMMAND_H
