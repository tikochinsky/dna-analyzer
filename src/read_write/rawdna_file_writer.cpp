#include "rawdna_file_writer.h"



RawdnaFileWriter::RawdnaFileWriter(const char *fileName):_fileName(fileName){}


RawdnaFileWriter::~RawdnaFileWriter(){}


void RawdnaFileWriter::write(const char* dataToWrite){

    _myFile.open(_fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    _myFile << dataToWrite;

    _myFile.close();
}
