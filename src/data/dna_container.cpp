#include "dna_container.h"

size_t DnaContainer::ID_COUNTER = 1;
size_t DnaContainer::NAME_COUNTER = 1;

void DnaContainer::addDna(DnaMetaData* dna){
    _idHash.insert(_idHash.end(), std::pair<size_t, DnaMetaData*>(dna->getId(), dna));
    _nameHash.insert(_nameHash.end(), std::pair<const char *, size_t>(dna->getName(), dna->getId()));
}