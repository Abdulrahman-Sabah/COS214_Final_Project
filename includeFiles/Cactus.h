
#ifndef CACTUS_H
#define CACTUS_H
/**
 * @file Cactus.h
 * @brief It defines the Cactus class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Plant.h"

/**
 * @class Cactus
 * @brief Represents a cactus plant available for purchase.
 * @details Inherits from the Plant abstract base class and overrides
 * required functions such as description(), price(), clone()and getType().
 */
class Cactus : public Plant {
public:
  /**
   * @brief Default constructor.
   *
   * @details Initializes a cactus plant with its predefined lifecycle state,
   * care strategy, and seasonal attributes (if assigned later).
   */
  Cactus();

  /**
   * @brief Destructor.
   *
   * @details Ensures proper cleanup if strategies or states have been set.
   */
  ~Cactus();

  /**
   * @brief Returns a short description of the cactus.
   * @return A descriptive string about the cactus.
   */
  std::string description() override;

  /**
   * @brief Returns the cost of purchasing a cactus plant.
   * @return The base price value.
   */
  double price() override;

  /**
   * @brief Clone this cactus instance using deep copy.
   *
   * @details Supports Prototype design pattern for duplicating plants.
   * @return A pointer to a new cloned Cactus object.
   */
  Plant *clone() override;

  /**
   * @brief Retrieve the plant type name for UI or categorization.
   * @return Always returns "Cactus".
   */
  std::string getType() const override { return "Cactus"; }
};

#endif // CACTUS_H
