#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

/**
 * @file WrapDecorator.h
 * @brief Adds wrapping decoration and cost to a plant.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantDecorations.h"

/**
 * @class WrapDecorator
 * @brief Decorator for adding wrapping.
 * @details Inherits from PlantDecorations to add wrapping type and cost.
 */
class WrapDecorator : public PlantDecorations {
private:
  /** @brief Type of wrapping */
  string wrapType;
  /** @brief Additional cost for wrapping */
  double wrapCost;

public:
  /**
   * @brief Constructor
   * @param item Plant to decorate
   * @param wrap Wrap type
   * @param cost Extra cost
   */
  WrapDecorator(Plant *item, string wrap, double cost);

  /**
   * @brief Get description of the wrapped plant
   * @return Description including wrap
   */
  string description() override;

  /**
   * @brief Get the price of the wrapped plant
   * @return Price + wrap cost
   */
  double price() override;

  /**
   * @brief Clone the wrapped plant
   * @return Cloned wrapped plant
   */
  Plant *clone() override;
};

#endif // WRAPDECORATOR_H
