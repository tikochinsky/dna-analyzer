#ifndef DNA_SEQUENCE_DNA_SEQUENCE_ERROR_H
#define DNA_SEQUENCE_DNA_SEQUENCE_ERROR_H

#include <exception>


class DnaSequenceError: public std::exception{
public:
    DnaSequenceError(const char *message): _msg(message){}

    const char* what() const throw (){
        return _msg;
    }

private:
    const char *_msg;
};


#endif //DNA_SEQUENCE_DNA_SEQUENCE_ERROR_H
