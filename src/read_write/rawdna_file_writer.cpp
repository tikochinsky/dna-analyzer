#include "rawdna_file_writer.h"

RawdnaFileWriter::~RawdnaFileWriter(){}

void RawdnaFileWriter::write(const char *fileName, const char* dataToWrite){

    _myFile.open(fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    _myFile << dataToWrite;

    _myFile.close();
}
