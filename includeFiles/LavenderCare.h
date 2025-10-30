/**
 * @file LavenderCare.h
 * @brief Concrete care strategy for lavender plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef LAVENDERCARE_H
#define LAVENDERCARE_H

#include "CareStrategy.h"

/**
 * @class LavenderCare
 * @brief Implements specific care requirements for lavender plants
 * 
 * This class provides the concrete implementation of care strategies
 * specifically tailored for lavender plants, including their unique
 * watering, sunlight, and maintenance requirements.
 */
class LavenderCare : public CareStrategy {
public:
    /**
     * @brief Applies lavender-specific care to a plant
     * @param plant The lavender plant to care for
     */
    void applyCare(Plant* plant) override;
    
    /**
     * @brief Virtual destructor
     */
    ~LavenderCare() override = default;
};

#endif 