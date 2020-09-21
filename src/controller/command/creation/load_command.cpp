#include "load_command.h"
#include "../../../view/read/rawdna_file_reader.h"
#include <sstream>


std::string LoadCommand::_rootDir = "data/dna_files/";


static bool isName(const Args& args, size_t index){
    return args[index][0] == '@';
}


static bool isId(const Args& args, size_t index){
    return args[index][0] == '#';
}


bool LoadCommand::hasValidNumOfArgs(const Args& args){
    return args.size() == 2 || args.size() == 3;
}


std::string LoadCommand::extractName(IWriter* writer,  DnaContainer* dnaContainer, const Args& args){
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
        size_t name_counter = 1;
        std::string file_name = args[1].substr(0, args[1].size()-7);

        s << file_name << name_counter;
        //is in the container
        while(dnaContainer->find(s.str())){
            s.clear();
            ++name_counter;
            s << file_name << name_counter;
        }
    }

    else{
        DnaContainer::ID_COUNTER--;
        writer->write("Invalid command\n");
        return "";
    }

    return s.str();
}


void LoadCommand::run(IWriter* writer, DnaContainer* dnaContainer, const Args& args){
    DnaMetaData* dnaMetaDataToAdd;

    std::string name = extractName(writer, dnaContainer, args);
    std::string fileName = _rootDir + args[1];
    RawdnaFileReader reader(fileName.c_str());


    if(name.empty()){
        return;
    }

    try{
        dnaMetaDataToAdd = new DnaMetaData(reader.read(), name.c_str(), DnaContainer::ID_COUNTER++);
    }

    catch(DnaSequenceError& e){
        writer->write(e.what());
        return;
    }

    catch(std::invalid_argument& e){
        writer->write(e.what());
        return;
    }

    catch(std::bad_alloc& e){
        writer->write(e.what());
        return;
    }

    dnaContainer->addDna(dnaMetaDataToAdd);
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
        s << "[" << dna.getId() << "] " << dna.getName() << ": " << dnaSeq.substr(0, 32) << "..." << dnaSeq.substr(dnaSize-3);
    }

    writer->write(s.str().c_str());
    std::cout << std::endl;
}

