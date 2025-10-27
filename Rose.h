
#ifndef ROSE_H
#define ROSE_H
#include "Plant.h"
#include <string>
using namespace std;

class Rose : public Plant {
public:
    Rose();
    ~Rose() = default;
    
    string description() override;
    double price() override;
    Plant* clone() override;
};

#endif
