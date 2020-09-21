#ifndef DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H
#define DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H

#include "i_writer.h"
#include <fstream>


class RawdnaFileWriter:public IWriter{
public:
    RawdnaFileWriter(const char *fileName);
    ~RawdnaFileWriter();
    void write(const char* dataToWrite);

private:
    std::ofstream _myFile;
    const char*_fileName;
};

#endif //DNA_ANALYZER_PROJECT_RAWDNA_FILE_WRITER_H
