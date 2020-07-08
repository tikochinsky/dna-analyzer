#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H

#include "i_reader.h"
#include <string>


class RawdnaFileReader:public IReader{
public:
    RawdnaFileReader(const char *fileName);
    ~RawdnaFileReader();
    const char* read();

private:
    const char *_fileName;
    std::string _input;
};


#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
