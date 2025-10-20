#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"
class Lavender : public Plant{
    public:
    Lavender();
    ~Lavender();
    Plant* clone();
};

#endif