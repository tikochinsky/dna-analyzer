#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H

#include "i_writer.h"
#include <fstream>

class RawdnaFileWriter:public IWriter{
public:
    ~RawdnaFileWriter();
    void write(const char *fileName, const char* dataToWrite);

private:
    std::ofstream _myFile;
};

inline RawdnaFileWriter::~RawdnaFileWriter(){}

#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H
