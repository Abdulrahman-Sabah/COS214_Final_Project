
#ifndef LAVENDER_H
#define LAVENDER_H

#include "Plant.h"

class Rose : public Plant 
{
public:
    Rose();
    ~Rose() override = default;
    std::string description() override;
    double price() override;
    Plant* clone() override;
};

#endif
