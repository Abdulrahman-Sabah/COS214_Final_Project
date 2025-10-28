#ifndef CACTUSCARE_H
#define CACTUSCARE_H

#include "CareStrategy.h"

class CactusCare : public CareStrategy 
{
public:
    void applyCare(Plant* plant) override;
    ~CactusCare() override = default;
};

#endif