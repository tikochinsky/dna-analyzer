#ifndef DNA_SEQUENCE_TXT_FILE_READER_H
#define DNA_SEQUENCE_TXT_FILE_READER_H

#include "i_reader.h"


class TxtFileReader:public IReader{
public:
    TxtFileReader(const char *fileName);
    ~TxtFileReader();
    const char* read();

private:
    const char *_fileName;
};

#endif //DNA_SEQUENCE_TXT_FILE_READER_H
