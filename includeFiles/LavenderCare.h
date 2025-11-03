#ifndef LAVENDERCARE_H
#define LAVENDERCARE_H
/**
 * @file LavenderCare.h
 * @brief Care strategy for lavender plants.
 * @author Git it done group members
 * @date 10-2025
 */

#include "CareStrategy.h"

/**
 * @class LavenderCare
 * @brief Applies lavender-specific care.
 */
class LavenderCare : public CareStrategy {
public:
    /**
     * @brief Apply lavender care actions
     * @param plant Target plant
     */
    void applyCare(Plant* plant) override;

    /**
     * @brief Destructor
     */
    ~LavenderCare() override = default;
};

#endif // LAVENDERCARE_H
