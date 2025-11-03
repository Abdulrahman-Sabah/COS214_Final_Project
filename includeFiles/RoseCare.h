#ifndef ROSECARE_H
#define ROSECARE_H

/**
 * @file RoseCare.h
 * @brief Care strategy for rose plants.
 */

#include "CareStrategy.h"

/**
 * @class RoseCare
 * @brief Applies rose-specific care.
 */
class RoseCare : public CareStrategy {
public:
    /**
     * @brief Apply rose care actions
     * @param plant Target plant
     */
    void applyCare(Plant* plant) override;

    /// Destructor
    ~RoseCare() override = default;
};

#endif // ROSECARE_H
