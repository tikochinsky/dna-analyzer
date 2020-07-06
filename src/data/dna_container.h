#ifndef DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
#define DNA_ANALYZER_PROJECT_DNA_CONTAINER_H

#include "dna_meta_data.h"
#include <map>




class DnaContainer{
public:
    static size_t ID_COUNTER;
    static size_t NAME_COUNTER;
    void addDna(DnaMetaData* dna);
private:
    std::map<size_t, DnaMetaData*> _idHash;
    std::map<const char *, size_t> _nameHash;

};


#endif //DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
