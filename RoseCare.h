/**
 * @file RoseCare.h
 * @brief Concrete care strategy for rose plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef ROSECARE_H
#define ROSECARE_H

#include "CareStrategy.h"

/**
 * @class RoseCare
 * @brief Implements specific care requirements for rose plants
 * 
 * This class provides the concrete implementation of care strategies
 * specifically tailored for rose plants, including their unique
 * watering, pruning, and fertilization requirements.
 */
class RoseCare : public CareStrategy {
public:
    /**
     * @brief Applies rose-specific care to a plant
     * @param plant The rose plant to care for
     */
    void applyCare(Plant* plant) override;
    
    /**
     * @brief Virtual destructor
     */
    ~RoseCare() override = default;
};

#endif
