#ifndef ROSE_H
#define ROSE_H

/**
 * @file Rose.h
 * @brief Concrete Rose plant type.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Plant.h"

/**
 * @class Rose
 * @brief Represents a rose plant.
 * @details Inherits from Plant and implements specific behavior for a rose
 * plant.
 */
class Rose : public Plant {
public:
  /** @brief Constructor */
  Rose();
  /** @brief Destructor */
  ~Rose() override;

  /**
   * @brief Get description of the rose plant
   * @return Description string
   */
  std::string description() override;

  /**
   * @brief Get price of the rose plant
   * @return Price value
   */
  double price() override;

  /**
   * @brief Clone the rose plant
   * @return Cloned Rose object
   */
  Plant *clone() override;

  /**
   * @brief Get the type of the plant
   * @return "Rose"
   */
  std::string getType() const override { return "Rose"; }
};

#endif // ROSE_H
