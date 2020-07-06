#ifndef DNA_ANALYZER_PROJECT_DNA_SEQUENCE_H
#define DNA_ANALYZER_PROJECT_DNA_SEQUENCE_H

#include <string>
#include <list>
#include "../read_write/i_reader.h"
#include "../read_write/i_writer.h"
#include "../error/dna_sequence_error.h"

class DnaSequence{
private:
    class Nucleotide{
    public:
        Nucleotide();
        Nucleotide(char c);

        const DnaSequence::Nucleotide& operator=(const Nucleotide& c2);
        operator char();

        DnaSequence::Nucleotide getPaired();

    private:
        char _c;

        static bool isValidChar(char c);
    };

    static const char *_dnaAlphabet;

    Nucleotide* _dnaSequence;
    size_t _length;

    DnaSequence::Nucleotide* getSeqToInit(const char* dnaSeq)const;
    DnaSequence::Nucleotide* getSeqToAssign(const DnaSequence& dnaSeq);
//    DnaSequence(size_t length);
//    void paired();
//    void reverse();
//
//    std::string getSequence();

public:
    DnaSequence(const char *c_string);
    DnaSequence(const std::string& string);
    DnaSequence(IReader& reader, const char* name);
    DnaSequence(const DnaSequence& dnaSequence);
    ~DnaSequence();
    DnaSequence& operator=(const DnaSequence& dnaSequence);

    DnaSequence::Nucleotide& operator[](size_t index)const;
//    size_t getSequenceLength()const;
//    DnaSequence slice(size_t start, size_t end)const;
//    DnaSequence getPairedStrand()const;
//    int findSubSeq(const DnaSequence& subSeq)const;
//    size_t countSubSeq(const DnaSequence& subSeq)const;
//    std::list<size_t> findAllSubSeq(const DnaSequence& subSeq)const;
//    std::list<DnaSequence> findConsensusSequences()const;
//    void write(IWriter& writer);
//
//    friend std::ostream& operator<<(std::ostream& output, const DnaSequence& dnaSequence);

};


//bool operator ==(const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);
//bool operator != (const DnaSequence& dnaSequence1, const DnaSequence& dnaSequence2);


#endif //DNA_ANALYZER_PROJECT_DNA_SEQUENCE_H
