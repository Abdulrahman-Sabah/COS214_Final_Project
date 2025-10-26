#ifndef ROSE_H
#define ROSE_H
#include "Plant.h"
class Rose : public Plant{
    public:
    Rose();
    virtual ~Rose() = default;
    Plant* clone();
    std::string description() override;
    double price() override;
};

#endif
