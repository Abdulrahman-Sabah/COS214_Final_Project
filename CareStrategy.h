#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

// #include "Plant.h"
#include <iostream>
class Plant;

class CareStrategy {
public:
    virtual void applyCare(Plant* plant) = 0;
    virtual ~CareStrategy() = default;
};

#endif 