#ifndef DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
#define DNA_ANALYZER_PROJECT_DNA_CONTAINER_H

#include "dna_meta_data.h"
#include <map>

static size_t ID_COUNTER=0;
static size_t NAME_COUNTER=1;


class DnaContainer{
public:
    void addDna(DnaMetaData* dna);
private:
    std::map<size_t, DnaMetaData*> _idHash;
    std::map<const char *, size_t> _nameHash;

};


#endif //DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
