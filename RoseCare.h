#ifndef ROSECARE_H
#define ROSECARE_H

#include "CareStrategy.h"

class RoseCare : public CareStrategy {
public:
    void applyCare(Plant* plant) override;
    ~RoseCare() override = default;
};

#endif
