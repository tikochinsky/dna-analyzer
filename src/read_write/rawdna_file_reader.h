#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H

#include "i_reader.h"



class RawdnaFileReader:public IReader{
public:
    RawdnaFileReader(const char *fileName);
    ~RawdnaFileReader();
    const char* read();

private:
    const char *_fileName;
};


#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_READER_H
