#ifndef DNA_ANALYZER_PROJECT_CONSOLEREADER_H
#define DNA_ANALYZER_PROJECT_CONSOLEREADER_H

#include "i_reader.h"
#include <string>

class ConsoleReader:public IReader{
public:
    ConsoleReader(const char *prompt);
    virtual const char* read();

private:
    const char* _prompt;
    std::string _input;
};

#endif //DNA_ANALYZER_PROJECT_CONSOLEREADER_H
