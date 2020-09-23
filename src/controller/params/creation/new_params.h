//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_PROJECT_NEW_ARGS_H
#define DNA_ANALYZER_PROJECT_NEW_ARGS_H

#include "../i_params.h"


class NewArgs: public IArgs {
public:
    NewArgs(const std::string& input);
    virtual void init(const std::string& input, DnaContainer* dnaContainer);
    bool hasValidNumOfArgs();
};


#endif //DNA_ANALYZER_PROJECT_NEW_ARGS_H
