#include "dna_meta_data.h"


DnaMetaData::DnaMetaData(const char *dna, const char *name, size_t id):_dna(dna), _name(name), _id(id){}


const char* DnaMetaData::getName()const {
    return _name;
}

size_t DnaMetaData::getId()const {
    return _id;
}

std::string DnaMetaData::getDna()const{
    return _dna.getSequence();
}
