#include "save_command.h"
#include <sstream>
#include "../../read_write/rawdna_file_writer.h"
#include <string>

void SaveCommand::run(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    if(!(args.size()== 2 || args.size()== 3)){
        writer->write("Invalid command");
        return;
    }


    if(args[1][0] == '#'){
        saveSeqById(writer, dnaContainer, args);
    }

    else if(args[1][0] == '@'){
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
        fileName = dnaContainer->getNameById(dnaId) + ".rawdna";
    }
    else{
        fileName = args[2] + ".rawdna";
    }


    dna = dnaContainer->find(dnaId);

    if(dna){
        RawdnaFileWriter fileWriter(fileName.c_str());
        fileWriter.write(dna->getDna().c_str());
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
        fileName = dnaName + ".rawdna";
    }
    else{
        fileName = args[2] + ".rawdna";
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
