#ifndef DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
#define DNA_ANALYZER_PROJECT_DNA_CONTAINER_H

#include "dna_meta_data.h"
#include <map>


class DnaContainer{//typedef
    typedef std::map<size_t, DnaMetaData*> sd_map;
    typedef std::map<std::string, size_t> ss_map;

public:
    static size_t ID_COUNTER;
    static size_t NAME_COUNTER;
    void addDna(DnaMetaData* dna);
    const DnaMetaData* find(size_t id);
    const DnaMetaData* find(const std::string&);
    std::string getNameById(size_t id);


private:
    sd_map _idHash;
    ss_map _nameHash;

};


#endif //DNA_ANALYZER_PROJECT_DNA_CONTAINER_H
