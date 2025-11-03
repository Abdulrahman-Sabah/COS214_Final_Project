
#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

/**
 * @file CareStrategy.h
 * @brief It defines the CareStrategy class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <iostream>
class Plant;

/**
 * @class CareStrategy
 * @brief Strategy interface for applying plant-specific care.
 *
 * Defines the structure for care behavior such as watering,
 * pruning, fertilizing, or seasonal actions. Concrete strategy
 * subclasses like CactusCare, RoseCare, and LavenderCare
 * implement their own logic for the applyCare() method.
 */
class CareStrategy {
public:
  /**
   * @brief Apply the care routine to the given plant.
   *
   * This function gets triggered either manually by a staff member,
   * or automatically via observers (e.g., lifecycle/state changes).
   *
   * @param plant Pointer to the plant requiring care.
   */
  virtual void applyCare(Plant *plant) = 0;

  /**
   * @brief Virtual destructor for safe polymorphic cleanup.
   */
  virtual ~CareStrategy() = default;
};

#endif // CARESTRATEGY_H
