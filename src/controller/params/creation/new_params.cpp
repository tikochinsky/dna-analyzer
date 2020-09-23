//
// Created by a on 9/22/20.
//

#include <sstream>
#include "new_args.h"
#include "../../../data/dna_container.h"
#include "../../error/args_error.h"


NewArgs::NewArgs(const std::string& input): Args(""){
    init(input, NULL);
}


void NewArgs::init(const std::string& input, DnaContainer* dnaContainer){
    Args::init(input, dnaContainer);
    static const char* seqName = "seq";
    std::stringstream s;
//enum - put each in place
//getters

    if(!hasValidNumOfArgs()){
        throw ArgsError("The number of arguments is not valid\n");
    }


    if(size() == 3 && isName(2)){
        s << _arguments[2].c_str() + 1;
        if(dnaContainer->find(s.str())){
            throw ArgsError("Name already exists. Execute with another name\n");
        }
    }

    else if(size() == 2){
        s << seqName << DnaContainer::NAME_COUNTER++;
        while(dnaContainer->find(s.str())){
            s << seqName << DnaContainer::NAME_COUNTER++;
        }
    }

    else{
        throw ArgsError("Invalid command\n");
    }
}


bool NewArgs::hasValidNumOfArgs(){
    return _arguments.size() == 2 || _arguments.size() == 3;
}
