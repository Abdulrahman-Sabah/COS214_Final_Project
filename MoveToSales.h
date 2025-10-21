#ifndef MOVETOSALES_H
#define MOVETOSALES_H

#include "Command.h"
#include <string>

class MoveToSales : public Commands {
private:
    std::string plantId;

public:
    explicit MoveToSales(const std::string& id);
    std::string getType() const override;
    std::string getData() const override;
};

#endif 
