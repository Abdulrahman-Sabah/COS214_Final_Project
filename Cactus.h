#ifndef CACTUS_H
#define CACTUS_H
#include "Plant.h"
class Cactus : public Plant{
    public:
    Cactus();
    ~Cactus();
    Plant* clone();
};

#endif
