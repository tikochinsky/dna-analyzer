//
// Created by a on 9/16/20.
//

#include "dup_command.h"
#include <string>
#include <sstream>


static bool isName(const Args& args, size_t index){
    return args[index][0] == '@';
}


static bool isId(const Args& args, size_t index){
    return args[index][0] == '#';
}


bool DupCommand::hasValidNumOfArgs(const Args& args){
    return args.size() == 2 || args.size() == 3;
}


std::string DupCommand::extractName(IWriter* writer,  DnaContainer* dnaContainer, const DnaMetaData* dnaToDup, const Args& args){
    std::stringstream s;
    size_t nameCounter = 1;

    std::string seqName(dnaToDup->getName());

    if(args.size() == 2){
        s << seqName << '_' << nameCounter++;
        while(dnaContainer->find(s.str())){
            s.str(std::string());
            s << seqName << '_' << nameCounter++;
        }
    }

    else{
        s << args[2];
        if(dnaContainer->find(s.str())){
            writer->write("Name of sequence already exists");
            return "";
        }
    }

    return s.str();
}


const DnaMetaData* DupCommand::getDnaToDup(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    const DnaMetaData *dnaToDup;

    if(!hasValidNumOfArgs(args)){
        writer->write("\nThe number of arguments is not valid");
        return NULL;
    }


    if(isId(args, 1)){
        size_t dnaId;
        std::istringstream ss(args[1].substr(1));
        ss >> dnaId;

        dnaToDup = dnaContainer->find(dnaId);
    }

    else if(isName(args, 1)){
        dnaToDup = dnaContainer->find(args[1].substr(1));
    }

    else{
        writer->write("Invalid sequence name\n");
        return NULL;
    }


    if(!dnaToDup){
        writer->write("Sequence not found\n");
        return NULL;
    }

    return dnaToDup;
}


void DupCommand::run(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    const DnaMetaData* dnaMetaDataToDup = getDnaToDup(writer, dnaContainer, args);

    if(!dnaMetaDataToDup){
        return;
    }

    DnaMetaData* dnaToAdd;
    std::string name = extractName(writer, dnaContainer, dnaMetaDataToDup, args);

    if(name.empty()){
        return;
    }

    try {
        dnaToAdd = new DnaMetaData(dnaMetaDataToDup->getDna().c_str(), name.c_str(), DnaContainer::ID_COUNTER++);
    }
    catch(DnaSequenceError& e){
        DnaContainer::ID_COUNTER--;
        writer->write(e.what());
        return;
    }

    dnaContainer->addDna(dnaToAdd);
    print(writer, *dnaToAdd);
}


void DupCommand::print(IWriter* writer, const DnaMetaData& dna){
    std::stringstream s;
    s << "[" << dna.getId() << "] " << dna.getName() << ": " << dna.getDna();
    writer->write(s.str().c_str());
    std::cout << std::endl;
}