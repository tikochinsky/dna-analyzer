#ifndef DNA_SEQUENCE_I_WRITER_H
#define DNA_SEQUENCE_I_WRITER_H

class IWriter{
public:
    virtual ~IWriter()=0;
    virtual void write(const char* dataToWrite)=0;

};

inline IWriter::~IWriter(){}

#endif //DNA_SEQUENCE_I_WRITER_H
