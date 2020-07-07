#include "new_command.h"
#include <string>
#include <sstream>

void NewCommand::run(IWriter* writer, DnaContainer& dnaContainer, const Args& args){
    static std::string seqName = "seq";
    DnaMetaData* dnaMetaDataToAdd;

    if(args.size() == 3 && args[2][0] == '@'){
        dnaMetaDataToAdd = new DnaMetaData(args[1].c_str(), args[2].c_str()+1, DnaContainer::ID_COUNTER++);
    }

    else if(args.size() == 2){
        std::stringstream s;
        s << seqName;
        s << DnaContainer::NAME_COUNTER++;
        dnaMetaDataToAdd = new DnaMetaData(args[1].c_str(), s.str().c_str(), DnaContainer::ID_COUNTER++);
    }

    else{
        std::cout << "\nInvalid command";
        return;
    }

    dnaContainer.addDna(dnaMetaDataToAdd);
    print(writer, *dnaMetaDataToAdd);
}


void NewCommand::print(IWriter* writer, const DnaMetaData& dna){
    std::stringstream s;
    s << "[" << dna.getId() << "] " << dna.getName() << ": " << dna.getDna();
    writer->write(s.str().c_str());
    std::cout << std::endl;
}