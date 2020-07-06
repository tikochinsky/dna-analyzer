#ifndef DNA_SEQUENCE_TXT_FILE_WRITER_H
#define DNA_SEQUENCE_TXT_FILE_WRITER_H
#include <fstream>
#include "i_writer.h"

class TxtFileWriter:public IWriter{
public:
    TxtFileWriter();
    ~TxtFileWriter();
    void write(const char *fileName, const char* dataToWrite);

private:
    std::ofstream _myFile;
};

#endif //DNA_SEQUENCE_TXT_FILE_WRITER_H
