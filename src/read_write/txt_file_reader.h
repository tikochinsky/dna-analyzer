#ifndef DNA_SEQUENCE_TXT_FILE_READER_H
#define DNA_SEQUENCE_TXT_FILE_READER_H

#include <fstream>
#include "i_reader.h"


class TxtFileReader:public IReader{
public:
    TxtFileReader(const char *fileName);
    ~TxtFileReader();
    const char* read();

private:
    std::ifstream _myFile;
    const char *_fileName;
};

#endif //DNA_SEQUENCE_TXT_FILE_READER_H
