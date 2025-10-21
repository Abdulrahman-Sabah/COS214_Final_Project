#ifndef CACTUS_H
#define CACTUS_H
#include "Plant.h"
class Cactus : public Plant{
    public:
    Cactus();
    virtual ~Cactus() = default;
    Plant* clone();
};

#endif
