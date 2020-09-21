#include "txt_file_writer.h"


TxtFileWriter::TxtFileWriter(const char *fileName):_fileName(fileName){}


TxtFileWriter::~TxtFileWriter(){}


void TxtFileWriter::write(const char* dataToWrite){

    _myFile.open(_fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    _myFile << dataToWrite;

    _myFile.close();
}
