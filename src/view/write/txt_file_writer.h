#ifndef DNA_SEQUENCE_TXT_FILE_WRITER_H
#define DNA_SEQUENCE_TXT_FILE_WRITER_H
#include <fstream>
#include "../write/i_writer.h"

class TxtFileWriter:public IWriter{
public:
    TxtFileWriter(const char *fileName);
    ~TxtFileWriter();
    void write(const char* dataToWrite);

private:
    std::ofstream _myFile;
    const char*_fileName;
};

#endif //DNA_SEQUENCE_TXT_FILE_WRITER_H
