/**
 * @file CareStrategy.h
 * @brief Abstract strategy interface for plant care operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include <iostream>

// Forward declaration
class Plant;

/**
 * @class CareStrategy
 * @brief Abstract base class implementing the Strategy pattern for plant care
 *
 * The CareStrategy class defines the interface for different plant care
 * algorithms. This allows the greenhouse system to use different care
 * strategies for different types of plants (e.g., CactusCare, RoseCare,
 * LavenderCare) without changing the plant classes themselves.
 *
 * Concrete strategies should inherit from this class and implement the
 * applyCare method with plant-specific care logic.
 */
class CareStrategy {
public:
  /**
   * @brief Applies care to the specified plant
   * @param plant Pointer to the plant that needs care
   *
   * This pure virtual method must be implemented by concrete strategy classes
   * to define specific care procedures for different plant types.
   */
  virtual void applyCare(Plant *plant) = 0;

  /**
   * @brief Virtual destructor for proper polymorphic cleanup
   */
  virtual ~CareStrategy() = default;
};

#endif