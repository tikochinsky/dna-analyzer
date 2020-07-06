#ifndef DNA_SEQUENCE_I_READER_H
#define DNA_SEQUENCE_I_READER_H


class IReader{
public:
    virtual ~IReader()=0;
    virtual const char* read()=0;

};

inline IReader::~IReader(){}

#endif //DNA_SEQUENCE_I_READER_H
