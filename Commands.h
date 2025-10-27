#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>

class Commands 
{
public:
    virtual ~Commands() = default;
    virtual std::string getType() const = 0;
    virtual std::string getData() const = 0;
};

#endif
