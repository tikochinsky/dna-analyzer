//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_PROJECT_I_ARGS_H
#define DNA_ANALYZER_PROJECT_I_ARGS_H

#include <string>

class DnaMetaData;
class DnaContainer;


class IArgs {
public:
    virtual ~IArgs(){}
    virtual void init(const std::string&, DnaContainer*) = 0;
    virtual std::string getName() = 0;
    virtual DnaMetaData* getDna() = 0;
};


#endif //DNA_ANALYZER_PROJECT_I_ARGS_H
