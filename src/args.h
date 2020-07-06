#ifndef DNA_ANALYZER_PROJECT_ARGS_H
#define DNA_ANALYZER_PROJECT_ARGS_H

#include <iostream>
#include <vector>
#include <string>

class Args{
public:
    Args(const std::string& input);
//    void addArgument(char* argument);
    const std::string& operator[](size_t index);
    void remove(size_t index);
    size_t size();

private:
    std::vector<std::string> _arguments;
};

#endif //DNA_ANALYZER_PROJECT_ARGS_H
