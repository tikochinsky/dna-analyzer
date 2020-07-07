#include "txt_file_reader.h"
#include <fstream>


TxtFileReader::TxtFileReader(const char *fileName):_fileName(fileName){}


TxtFileReader::~TxtFileReader(){}


const char* TxtFileReader::read(){
    std::string data;
    std::string line;
    std::ifstream _myFile;

    _myFile.open(_fileName);

    if (_myFile.fail()){
        throw std::invalid_argument("Opening file failed\n");
    }

    while(std::getline(_myFile, line))
    {
        data += line;
    }

    _myFile.close();

    return data.c_str();
}
