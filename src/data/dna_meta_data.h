#ifndef DNA_ANALYZER_PROJECT_DNA_META_DATA_H
#define DNA_ANALYZER_PROJECT_DNA_META_DATA_H

#include "dna_sequence.h"
#include <string>

class DnaMetaData{
public:
    DnaMetaData(const char *dna, const char *name, size_t id);
    const char* getName()const;
    size_t getId()const;
    std::string getDna()const;

private:
    DnaSequence _dna;
    const char* _name;
    size_t _id;
};

#endif //DNA_ANALYZER_PROJECT_DNA_META_DATA_H
