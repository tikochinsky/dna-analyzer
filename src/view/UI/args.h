#ifndef DNA_ANALYZER_PROJECT_ARGS_H
#define DNA_ANALYZER_PROJECT_ARGS_H

#include <iostream>
#include <vector>
#include <string>
#include "i_args.h"


class Args: public IArgs{
public:
    Args(const std::string& input);
    const std::string& operator[](size_t index)const;
    size_t size()const;
    bool empty();

    virtual void init(const std::string& input, DnaContainer* dnaContainer);
    virtual std::string getName();
    virtual DnaMetaData* getDna();

protected:
    static bool isName(const Args& args, size_t index);
    static bool isId(const Args& args, size_t index);

private:
    std::vector<std::string> _arguments;
    void addArgument(const std::string& word);
};

#endif //DNA_ANALYZER_PROJECT_ARGS_H
