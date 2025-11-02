
/**
 * @file Rose.h
 * @brief Header file for the Rose class
 */

#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"

/**
 * @class Rose
 * @brief Concrete implementation of Plant representing a Rose
 *
 * This class implements the Prototype pattern by providing a clone() method
 * and represents a specific type of plant with its own characteristics,
 * care requirements, and seasonal preferences.
 */
class Rose : public Plant {
public:
  /**
   * @brief Default constructor for Rose
   * Creates a rose with appropriate care strategy and seasonal settings
   */
  Rose();

  /**
   * @brief Destructor for Rose
   */
  ~Rose();

  /**
   * @brief Get description of the rose
   * @return String description of the rose plant
   */
  std::string description() override;

  /**
   * @brief Get the price of the rose
   * @return Price of the rose as a double value
   */
  double price() override;

  /**
   * @brief Clone this rose (Prototype pattern)
   * @return Pointer to a new Rose instance that is a copy of this one
   */
  Plant *clone() override;
};

#endif