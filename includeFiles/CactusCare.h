/**
 * @file CactusCare.h
 * @brief Concrete strategy for cactus plant care
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CACTUSCARE_H
#define CACTUSCARE_H

#include "CareStrategy.h"

/**
 * @class CactusCare
 * @brief Concrete strategy implementation for caring for cactus plants
 *
 * CactusCare implements the Strategy pattern to provide specific care
 * instructions for cactus plants. Cacti require minimal watering,
 * maximum sunlight, and well-draining soil.
 */
class CactusCare : public CareStrategy {
public:
  /**
   * @brief Applies cactus-specific care to the plant
   * @param plant Pointer to the plant receiving care
   *
   * Implements care routine specific to cacti including:
   * - Minimal watering (only when soil is completely dry)
   * - Direct sunlight placement
   * - Well-draining soil requirements
   */
  void applyCare(Plant *plant) override;

  /**
   * @brief Virtual destructor for proper cleanup
   */
  ~CactusCare() override = default;
};

#endif