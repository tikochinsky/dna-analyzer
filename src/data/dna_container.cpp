#include "dna_container.h"

size_t DnaContainer::ID_COUNTER = 1;
size_t DnaContainer::NAME_COUNTER = 1;



DnaContainer::~DnaContainer(){
    for (sd_map::iterator it = _idHash.begin(); it != _idHash.end(); ++it){
        delete it->second;
    }
}


void DnaContainer::addDna(DnaMetaData* dna){
    _idHash.insert(std::pair<size_t, DnaMetaData*>(dna->getId(), dna));
    _nameHash.insert(std::pair<std::string, size_t>(dna->getName(), dna->getId()));
}


//problem: doesn't find.
const DnaMetaData* DnaContainer::find(size_t id){
    sd_map::const_iterator pos = _idHash.find(id);

    if(pos == _idHash.end()){
        return NULL;
    }
    return _idHash.find(id)->second;
}


const DnaMetaData* DnaContainer::find(const std::string& name){
    ss_map::iterator pos = _nameHash.find(name);

    if(pos == _nameHash.end()){
        return NULL;
    }
    return _idHash.find(pos->second)->second;
}


std::string DnaContainer::getNameById(size_t id){
    for (ss_map::iterator it = _nameHash.begin(); it != _nameHash.end(); ++it){
        if (it->second == id){
            return it->first;
        }
    }
    return "";
}
