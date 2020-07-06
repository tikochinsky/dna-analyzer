#ifndef DNA_ANALYZER_PROJECT_ARGS_H
#define DNA_ANALYZER_PROJECT_ARGS_H

#include <iostream>
#include <vector>


class Args{
public:
    void addArgument(char *argument);
    char* operator[](size_t index);
    void remove(size_t index);
    size_t size();

private:
    std::vector<char*> _arguments;
};

#endif //DNA_ANALYZER_PROJECT_ARGS_H
