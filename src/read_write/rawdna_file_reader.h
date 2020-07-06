#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H

#include <fstream>
#include "i_reader.h"


class RawdnaFileReader:public IReader{
public:
    virtual ~RawdnaFileReader();
    virtual const char* read(const char* fileName);

private:
    std::ifstream _myFile;
};

#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
