#include "txt_file_writer.h"


TxtFileWriter::TxtFileWriter(){}


TxtFileWriter::~TxtFileWriter(){}


void TxtFileWriter::write(const char *fileName, const char* dataToWrite){

    _myFile.open(fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    _myFile << dataToWrite;

    _myFile.close();
}
