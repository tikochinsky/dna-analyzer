#include "new_command.h"
#include <string>
#include <sstream>

void NewCommand::run(DnaContainer& dnaContainer, Args args){
    static std::string seqName = "seq";
    DnaMetaData* dnaMetaDataToAdd;

    if(args.size() == 2 && args[1][0] == '@'){
        dnaMetaDataToAdd = new DnaMetaData(args[0].c_str(), args[1].c_str(), ID_COUNTER++);
    }

    else if(args.size() == 1){
        std::stringstream s;
        s << seqName;
        s << NAME_COUNTER++;
        char *tempName;
        s >> tempName;
        dnaMetaDataToAdd = new DnaMetaData(args[0].c_str(), tempName, ID_COUNTER++);
    }

    else{
        std::cout << "\nInvalid command";
        return;
    }

    dnaContainer.addDna(dnaMetaDataToAdd);
    std::cout << std::endl;
    print(*dnaMetaDataToAdd);
}


void NewCommand::print(const DnaMetaData& dna){
    std::cout << "[" << dna.getId() << "] " << dna.getName() << " ";//print seq
    std::cout << std::endl;
}