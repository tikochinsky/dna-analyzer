#ifndef DNA_ANALYZER_PROJECT_CONSOLEREADER_H
#define DNA_ANALYZER_PROJECT_CONSOLEREADER_H

#include "i_reader.h"

class ConsoleReader:public IReader{
public:
    ConsoleReader(const char *prompt);
    virtual const char* read();

private:
    const char* _prompt;
};

#endif //DNA_ANALYZER_PROJECT_CONSOLEREADER_H
