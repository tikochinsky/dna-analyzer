//
// Created by a on 9/22/20.
//

#ifndef DNA_ANALYZER_PROJECT_ARGS_FACTORY_H
#define DNA_ANALYZER_PROJECT_ARGS_FACTORY_H

#include "i_args.h"
#include "../smart_pointers/shared_ptr.h"
#include <map>


class ArgsFactory {
public:
    static ArgsFactory* getInstance();
    static void resetInstance();

    SharedPtr<IArgs> getArgs(const std::string& input);

private:
    ArgsFactory();
    static ArgsFactory* _obj;

    std::map<std::string, SharedPtr<IArgs> > _argsMap;
};


#endif //DNA_ANALYZER_PROJECT_ARGS_FACTORY_H
