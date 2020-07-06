#include "rawdna_file_reader.h"


RawdnaFileReader::RawdnaFileReader(const char *fileName):_fileName(fileName){}


RawdnaFileReader::~RawdnaFileReader(){}


const char* RawdnaFileReader::read(){
    std::string data;

    _myFile.open(_fileName);

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
