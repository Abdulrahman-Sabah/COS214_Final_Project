#ifndef POTDECORATOR_H
#define POTDECORATOR_H

/**
 * @file PotDecorator.h
 * @brief Adds pot decoration and cost to a plant.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantDecorations.h"

/**
 * @class PotDecorator
 * @brief Decorator for adding a pot.
 * @details Inherits from PlantDecorations to add pot type decorations and cost
 * to a plant.
 */
class PotDecorator : public PlantDecorations {
private:
  /** @brief Pot type */
  string potType;
  /** @brief Additional cost for the pot */
  double potCost;

public:
  /**
   * @brief Constructor
   * @param item Plant to decorate
   * @param pot Pot type
   * @param cost Extra cost
   */
  PotDecorator(Plant *item, string pot, double cost);

  /**
   * @brief Get description including pot
   * @return Description including pot
   */
  string description() override;

  /**
   * @brief Get price including pot cost
   * @return Price + pot cost
   */
  double price() override;

  /**
   * @brief Clone the decorator and wrapped plant
   * @return Cloned Plant pointer
   */
  Plant *clone() override;
};

#endif // POTDECORATOR_H
