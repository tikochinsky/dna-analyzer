#include "txt_file_reader.h"


TxtFileReader::~TxtFileReader(){}


const char* TxtFileReader::read(const char *fileName){
    std::string data;

    _myFile.open(fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    std::string line;

    while(std::getline(_myFile, line))
    {
        data += line;
    }

    _myFile.close();

    return data.c_str();
}
