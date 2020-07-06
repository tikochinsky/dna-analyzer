#ifndef DNA_SEQUENCE_TXT_FILE_READER_H
#define DNA_SEQUENCE_TXT_FILE_READER_H

#include <fstream>
#include "i_reader.h"


class TxtFileReader:public IReader{
public:
    ~TxtFileReader();
    const char* read(const char *fileName);

private:
    std::ifstream _myFile;
};

#endif //DNA_SEQUENCE_TXT_FILE_READER_H
