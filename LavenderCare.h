#ifndef LAVENDERCARE_H
#define LAVENDERCARE_H

#include "CareStrategy.h"

class LavenderCare : public CareStrategy {
public:
    void applyCare(Plant* plant) override;
    ~LavenderCare() override = default;
};

#endif 