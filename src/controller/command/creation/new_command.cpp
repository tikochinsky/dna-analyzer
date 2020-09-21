#include "new_command.h"
#include <string>
#include <sstream>


static bool isName(const Args& args, size_t index){
    return args[index][0] == '@';
}


static bool isId(const Args& args, size_t index){
    return args[index][0] == '#';
}


bool NewCommand::hasValidNumOfArgs(const Args& args){
    return args.size() == 2 || args.size() == 3;
}


std::string NewCommand::extractName(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    static const char* seqName = "seq";
    std::stringstream s;


    if(!hasValidNumOfArgs(args)){
        writer->write("The number of arguments is not valid\n");
        return NULL;
    }


    if(args.size() == 3 && isName(args, 2)){
        s << args[2].c_str() + 1;
        if(dnaContainer->find(s.str())){
            writer->write("Name already exists. Execute with another name\n");
            return "";
        }
    }

    else if(args.size() == 2){
        s << seqName << DnaContainer::NAME_COUNTER++;
        while(dnaContainer->find(s.str())){
            s << seqName << DnaContainer::NAME_COUNTER++;
        }
    }

    else{
        writer->write("Invalid command\n");
        return "";
    }

    return s.str();
}



void NewCommand::run(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    DnaMetaData* dnaMetaDataToAdd;

    std::string name = extractName(writer, dnaContainer, args);

    if(name.empty()){
        return;
    }

    try {
        dnaMetaDataToAdd = new DnaMetaData(args[1].c_str(), name.c_str(), DnaContainer::ID_COUNTER++);
    }
    catch(DnaSequenceError& e){
        DnaContainer::ID_COUNTER--;
        if(args.size() == 2){
            DnaContainer::NAME_COUNTER--;
        }
        writer->write(e.what());
        return;
    }

    dnaContainer->addDna(dnaMetaDataToAdd);
    print(writer, *dnaMetaDataToAdd);
}


void NewCommand::print(IWriter* writer, const DnaMetaData& dna){
    std::stringstream s;
    s << "[" << dna.getId() << "] " << dna.getName() << ": " << dna.getDna();
    writer->write(s.str().c_str());
    std::cout << std::endl;
}