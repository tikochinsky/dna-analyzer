#include "new_command.h"
#include <string>
#include <sstream>

void NewCommand::run(IWriter* writer, DnaContainer& dnaContainer, const Args& args){
    static const char* seqName = "seq";
    std::stringstream s;
    DnaMetaData* dnaMetaDataToAdd;

    //choose name or return error
    if(args.size() == 3 && args[2][0] == '@'){
        s << args[2].c_str() + 1;
    }

    else if(args.size() == 2){
        s << seqName << DnaContainer::NAME_COUNTER++;
    }

    else{
        writer->write("\nInvalid command");
        return;
    }



    try {
        dnaMetaDataToAdd = new DnaMetaData(args[1].c_str(), s.str().c_str(), DnaContainer::ID_COUNTER++);
    }
    catch(DnaSequenceError& e){
        writer->write(e.what());
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