#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"
class Lavender : public Plant{
    public:
    Lavender();
    virtual ~Lavender() = default;
    Plant* clone();
};

#endif
