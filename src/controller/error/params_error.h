//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_PROJECT_ARGS_ERROR_H
#define DNA_ANALYZER_PROJECT_ARGS_ERROR_H

#include <exception>


class ArgsError: public std::exception{
public:
    ArgsError(const char *message): _msg(message){}

    const char* what() const throw (){
        return _msg;
    }

private:
    const char *_msg;
};

#endif //DNA_ANALYZER_PROJECT_ARGS_ERROR_H
