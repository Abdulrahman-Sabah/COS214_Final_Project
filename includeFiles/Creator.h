/**
 * @file Creator.h
 * @brief Abstract creator class for Factory Method pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CREATOR_H
#define CREATOR_H

#include "Plant.h"

/**
 * @class Creator
 * @brief Abstract base class for the Factory Method pattern
 *
 * The Creator class defines the interface for creating Plant objects
 * using the Factory Method design pattern. Concrete creators will
 * inherit from this class and implement the factoryMethod to create
 * specific types of plants.
 */
class Creator {
protected:
  Plant *product; ///< The plant product created by this factory

  /**
   * @brief Pure virtual factory method for creating plants
   * @return Pointer to a newly created Plant object
   *
   * This method must be implemented by concrete creators to
   * define what type of plant they create.
   */
  virtual Plant *factoryMethod() const = 0;

public:
  /**
   * @brief Virtual destructor for proper polymorphic cleanup
   */
  virtual ~Creator() {}
};

#endif