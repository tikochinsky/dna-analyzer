#include "save_command.h"
#include <sstream>
#include "../../../view/write/rawdna_file_writer.h"
#include <string>
#include <fstream>


std::string SaveCommand::_rootDir = "data/dna_files/";



static bool isName(const Args& args, size_t index){
    return args[index][0] == '@';
}


static bool isId(const Args& args, size_t index){
    return args[index][0] == '#';
}


static void writeDnaToFile(const std::string& fileName, IWriter* writer, const DnaMetaData* dna){
    if (std::ifstream(fileName.c_str()))
    {
        writer->write("File name already exists\n") ;
        return;
    }

    try {
        RawdnaFileWriter fileWriter(fileName.c_str());
        fileWriter.write(dna->getDna().c_str());
    }

    catch(std::invalid_argument& e){
        writer->write("File path is not valid\n") ;
        return;
    }
}

bool SaveCommand::hasValidNumOfArgs(const Args& args){
    return args.size() == 2 || args.size() == 3;
}


void SaveCommand::run(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    if(!hasValidNumOfArgs(args)){
        writer->write("Invalid command\n");
        return;
    }


    if(isId(args, 1)){
        saveSeqById(writer, dnaContainer, args);
    }

    else if(isName(args, 1)){
        saveSeqByName(writer, dnaContainer, args);
    }

    else{
        writer->write("Invalid command\n");
        return;
    }
}


void SaveCommand::print(IWriter* writer, const DnaMetaData& dna){}


void SaveCommand::saveSeqById(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    const DnaMetaData* dna;
    std::string fileName;
    size_t dnaId;
    std::istringstream ss(args[1].substr(1));
    ss >> dnaId;

    if(args.size() == 2) {
        fileName = _rootDir + dnaContainer->getNameById(dnaId) + ".rawdna";
    }
    else{
        fileName = _rootDir + args[2] + ".rawdna";
    }

    dna = dnaContainer->find(dnaId);

    if(dna){
        writeDnaToFile(fileName, writer, dna);
    }

    else{
        writer->write("Dna not found\n") ;
        return;
    }
}


void SaveCommand::saveSeqByName(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    const DnaMetaData* dna;
    std::string fileName;
    std::string dnaName = args[1].substr(1);

    if(args.size() == 2) {
        fileName = _rootDir + dnaName + ".rawdna";
    }
    else{
        fileName = _rootDir + args[2] + ".rawdna";
    }


    dna = dnaContainer->find(dnaName);

    if(dna){
        RawdnaFileWriter fileWriter(fileName.c_str());
        fileWriter.write(dna->getDna().c_str());
    }
    else{
        writer->write("Dna not found\n") ;
        return;
    }
}
