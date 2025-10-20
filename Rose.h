#ifndef ROSE_H
#define ROSE_H
#include "Plant.h"
class Rose : public Plant{
    public:
    Rose();
    ~Rose();
    Plant* clone();
};

#endif