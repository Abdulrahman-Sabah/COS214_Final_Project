#ifndef SUCCULENTCARE_H
#define SUCCULENTCARE_H

#include "CareStrategy.h"

class SucculentCare : public CareStrategy {
public:
    void applyCare(Plant& plant) override;
    ~SucculentCare() override = default;
};

#endif 