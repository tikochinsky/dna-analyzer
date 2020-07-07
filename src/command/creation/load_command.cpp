#include "load_command.h"
#include "../../read_write/rawdna_file_reader.h"
#include <sstream>


void LoadCommand::run(IWriter* writer, DnaContainer& dnaContainer, const Args& args){
    DnaMetaData* dnaMetaDataToAdd;

    if(args.size() < 2){
        return;
    }

    RawdnaFileReader reader(args[1].c_str());

    if(args.size() == 2 && args[1][0] == '@'){
        dnaMetaDataToAdd = new DnaMetaData(reader.read(), args[2].c_str()+1, DnaContainer::ID_COUNTER++);
    }

    else if(args.size() == 2){
        std::stringstream s;
        size_t name_counter = 1;
        std::string file_name = args[1].substr(args[1].size()-6);

        s << file_name << name_counter;
        //in the container
        while(dnaContainer.find(s.str().c_str())){
            s.clear();
            s << file_name << ++name_counter;
        }
        dnaMetaDataToAdd = new DnaMetaData(reader.read(), s.str().c_str(), DnaContainer::ID_COUNTER++);
    }

    else{
        std::cout << "\nInvalid command";
        return;
    }

    dnaContainer.addDna(dnaMetaDataToAdd);
    print(writer, *dnaMetaDataToAdd);
}

void LoadCommand::print(IWriter* writer, const DnaMetaData& dna){
    std::stringstream s;
    std::string dnaSeq = dna.getDna();

    if(dnaSeq.size()<=40){
        s << "[" << dna.getId() << "] " << dna.getName() << ": " << dnaSeq;
    }

    else{
        size_t dnaSize = dnaSeq.size();
        s << "[" << dna.getId() << "] " << dna.getName() << ": " << dnaSeq.substr(32) << "..." << dnaSeq.substr(dnaSize-4, dnaSize-1);
    }

    writer->write(s.str().c_str());
    std::cout << std::endl;
}