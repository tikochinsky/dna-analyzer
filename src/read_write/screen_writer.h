#ifndef DNA_ANALYZER_PROJECT_SCREEN_WRITER_H
#define DNA_ANALYZER_PROJECT_SCREEN_WRITER_H

#include "i_writer.h"

class ScreenWriter:public IWriter{
public:
    void write(const char* dataToWrite);
};

#endif //DNA_ANALYZER_PROJECT_SCREEN_WRITER_H
