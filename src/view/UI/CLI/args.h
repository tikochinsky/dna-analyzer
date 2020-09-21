#ifndef DNA_ANALYZER_PROJECT_ARGS_H
#define DNA_ANALYZER_PROJECT_ARGS_H

#include <iostream>
#include <vector>
#include <string>

class Args{
public:
    Args(const std::string& input);
    const std::string& operator[](size_t index)const;
    size_t size()const;
    bool empty();

private:
    std::vector<std::string> _arguments;
    void addArgument(const std::string& word);
};

#endif //DNA_ANALYZER_PROJECT_ARGS_H
