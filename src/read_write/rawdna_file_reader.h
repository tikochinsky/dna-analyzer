#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H

#include <fstream>
#include "i_reader.h"



class RawdnaFileReader:public IReader{
public:
    RawdnaFileReader(const char *fileName);
    ~RawdnaFileReader();
    const char* read();

private:
    std::ifstream _myFile;
    const char *_fileName;
};


#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
