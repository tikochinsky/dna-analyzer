
#include <iostream>
#include <algorithm>
#include "string.h"

#include "dna_sequence.h"


const char * DnaSequence::_dnaAlphabet = "GCTA";


DnaSequence::Nucleotide* DnaSequence::getSeqToInit(const char* dnaSeq)const throw(DnaSequenceError)
{
    size_t i;
    size_t lengthOfSeq= strlen(dnaSeq);

    Nucleotide *allocated_dna_seq = new Nucleotide[lengthOfSeq];

    for (i = 0; i < lengthOfSeq; ++i) {
        allocated_dna_seq[i] = Nucleotide(dnaSeq[i]);
    }

    return allocated_dna_seq;
}


DnaSequence::Nucleotide* DnaSequence::getSeqToAssign(const DnaSequence& dnaSeq)
{
    Nucleotide *allocated_dna_seq = new Nucleotide[dnaSeq._length];

    for(size_t i=0; i<dnaSeq._length; ++i){
        allocated_dna_seq[i] = dnaSeq[i];
    }

    return allocated_dna_seq;
}


DnaSequence::DnaSequence(const char *c_string):_dnaSequence(getSeqToInit(c_string)),_length(strlen(c_string)){}


DnaSequence::DnaSequence(const std::string& string):_dnaSequence(getSeqToInit(string.c_str())),_length(string.length()){}


DnaSequence::DnaSequence(IReader& reader): _dnaSequence(getSeqToInit(reader.read())), _length(strlen(reader.read())){}


DnaSequence::DnaSequence(const DnaSequence& dnaSequence):_dnaSequence(getSeqToAssign(dnaSequence)), _length(dnaSequence._length){}


//DnaSequence::DnaSequence(size_t length):_dnaSequence(new Nucleotide[length]), _length(length){}


DnaSequence::~DnaSequence()
{
    delete[] _dnaSequence;
}


DnaSequence& DnaSequence::operator=(const DnaSequence& dnaSequence) throw(DnaSequenceError)
{
    try{
        DnaSequence::Nucleotide* temp = getSeqToAssign(dnaSequence);
        delete[] _dnaSequence;
        _dnaSequence = temp;
        _length = dnaSequence._length;
        return *this;
    }
    catch(std::exception& e) {
        throw DnaSequenceError("Too much long sequence to copy\n");
    }
}


//DnaSequence::Nucleotide& DnaSequence::operator[](size_t index)const  throw(DnaSequenceError)
//{
//    if(index < _length)
//        return _dnaSequence[index];
//    throw DnaSequenceError("Index out of range\n");
//}
//
//
//size_t DnaSequence::getSequenceLength()const
//{
//    return _length;
//}
//
//
//DnaSequence DnaSequence::slice(size_t start, size_t end)const
//{
//    size_t i;
//
//    DnaSequence slicedDnaSeq(std::max(size_t(0), end-start));
//
//    for(i=start; i<end; i++){
//        slicedDnaSeq[i-start] = (*this)[i];
//    }
//
//    return slicedDnaSeq;
//}
//
//DnaSequence DnaSequence::getPairedStrand()const{
//    DnaSequence pairedStrand(*this);
//    pairedStrand.paired();
//    pairedStrand.reverse();
//    return pairedStrand;
//}
//
//
///*what to do about the type?-----------*/
//int DnaSequence::findSubSeq(const DnaSequence& subSeq)const{
//    size_t i, j, k;
//
//    if(!subSeq._length)
//        return  0;
//
//    for(i=0; i<_length; i++){
//        if(_dnaSequence[i] == subSeq[0]){
//            for(j=0, k=i; j<subSeq._length&&k<_length; j++, k++){
//                if(_dnaSequence[k] != subSeq[j])
//                    break;
//            }
//            if(k-i == subSeq._length)
//                break;
//        }
//    }
//
//    if(i!=_length)
//        return (int)i;
//
//    else
//        return -1;
//
//}
//
//
//size_t DnaSequence::countSubSeq(const DnaSequence& subSeq)const{
//    std::list<size_t> index_list = findAllSubSeq(subSeq);
//    return index_list.size();
//}
//
//
//std::list<size_t> DnaSequence::findAllSubSeq(const DnaSequence& subSeq)const{
//    std::list<size_t> index_list;
//    int index;
//
//    for(size_t i=0; i<_length; i++){
//
//        index = slice(i, _length).findSubSeq(subSeq);
//        if(index != -1){
//            index_list.push_back((size_t )index + i);
//            i += index;
//        }
//
//    }
//
//    return index_list;
//}
//
//
//std::list<DnaSequence> DnaSequence::findConsensusSequences()const{
//    size_t i, j;
//    std::list<DnaSequence> consensusSequences;
//    DnaSequence endCodon("");
//
//    for(i=0; i+2<_length; i++) {
//
//        if(slice(i, i+3) == "ATG"){
//            for (j = i + 3; j + 2 < _length; j += 3) {
//                endCodon = slice(j, j+3);
//
//                if(endCodon == "TAG" || endCodon == "TAA" || endCodon == "TGA"){
//                    consensusSequences.push_back(slice(i, j+3));
//                }
//            }
//
//        }
//    }
//
//    return consensusSequences;
//
//}
//
//
//void DnaSequence::write(IWriter& writer){
//    writer.write(getSequence().c_str());
//}
//
//
////private
//void DnaSequence::paired() {
//    for(size_t i=0; i<_length; i++){
//        _dnaSequence[i] = _dnaSequence[i].getPaired();
//    }
//}
//
//void DnaSequence::reverse(){
//    for(size_t i=0; i<_length/2; ++i){
//        std::swap(_dnaSequence[i], _dnaSequence[_length-i-1]);
//    }
//}
//
//
//std::string DnaSequence::getSequence(){
//    std::string dnaSequenceStr;
//    for(size_t i=0; i<_length; ++i) {
//        dnaSequenceStr += (*this)[i];
//    }
//
//    return dnaSequenceStr;
//}
//
//
//
////---------
//std::ostream& operator<<(std::ostream& output, const DnaSequence& dnaSequence)
//{
//    for(size_t i=0; i<dnaSequence._length; ++i)
//    {
//        output << dnaSequence[i];
//    }
//
//    output <<  std::endl;
//    return output;
//}
//
//
//bool operator ==(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
//{
//    if(dnaSequence1.getSequenceLength() != dnaSequence2.getSequenceLength())
//        return false;
//
//    for(size_t i = 0; i< dnaSequence1.getSequenceLength(); ++i)
//    {
//        if(dnaSequence1[i] != dnaSequence2[i])
//            return false;
//    }
//
//    return true;
//}
//
//
//bool operator != (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2)
//{
//    size_t i;
//    for(i = 0; i< std::min(dnaSequence1.getSequenceLength(), dnaSequence2.getSequenceLength()); ++i)
//    {
//        if(dnaSequence1[i] != dnaSequence2[i])
//            return true;
//    }
//
//    return dnaSequence1[i] != '\0' || dnaSequence2[i] != '\0';
//}


//--------Nucleotide---------
DnaSequence::Nucleotide::Nucleotide() {}
DnaSequence::Nucleotide::Nucleotide(char c):_c(c) {
    if(!isValidChar(c)){
        throw DnaSequenceError("Invalid nucleotide to assign\n");
    }
}

const DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const Nucleotide& c2){
    _c = c2._c;
    return *this;
}


DnaSequence::Nucleotide::operator char()
{
    return _c;
}


DnaSequence::Nucleotide DnaSequence::Nucleotide::getPaired(){
    char paired;

    if(_c == 'G')
        paired = 'C';
    if(_c == 'C')
        paired = 'G';
    if(_c == 'A')
        paired = 'T';
    if(_c == 'T')
        paired = 'A';

    return Nucleotide(paired);
}


bool DnaSequence::Nucleotide::isValidChar(char c)
{
    return strchr(_dnaAlphabet, c);
}