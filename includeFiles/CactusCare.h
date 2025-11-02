#ifndef CACTUSCARE_H
#define CACTUSCARE_H

/**
 * @file CactusCare.h
 * @brief Care strategy implementation tailored for cactus plants.
 *
 * This strategy defines how a cactus should be cared for, such as
 * low-frequency watering and minimal maintenance. Used in the
 * Strategy design pattern to change plant care behavior dynamically.
 */

#include "CareStrategy.h"

/**
 * @class CactusCare
 * @brief Concrete strategy providing cactus-appropriate plant care.
 *
 * Implements the CareStrategy interface by offering a behavior
 * that mimics real-world cactus care needs. Typically includes
 * sparse watering and sunlight-related actions.
 */
class CactusCare : public CareStrategy {
public:
    /**
     * @brief Apply cactus-specific care to the given plant.
     *
     * This can include:
     * - Low water usage
     * - No pruning
     * - Sunlight exposure check
     *
     * @param plant Pointer to the plant receiving care.
     */
    void applyCare(Plant* plant) override;

    /**
     * @brief Virtual default destructor for safe polymorphic deletion.
     */
    ~CactusCare() override = default;
};

#endif // CACTUSCARE_H
