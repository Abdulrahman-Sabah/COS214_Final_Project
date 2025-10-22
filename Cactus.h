#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"
#include <string>

class Cactus : public Plant {
public:
    Cactus();
    ~Cactus() override;               
    Plant* clone() override;
    std::string description() override;
    double price() override;
};

#endif
