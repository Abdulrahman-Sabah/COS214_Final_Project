
#ifndef LAVENDER_H
#define LAVENDER_H

#include "Plant.h"

class Cactus : public Plant 
{
public:
    Cactus();
    ~Cactus();
    std::string description() override;
    double price() override;
    Plant* clone() override;
};

#endif