/**
 * @file PotDecorator.h
 * @brief Concrete decorator for adding pots to plants
 * @author COS214 Students
 * @date 2024
 */

#ifndef POTDECORATOR_H
#define POTDECORATOR_H

#include "PlantDecorations.h"

/**
 * @class PotDecorator
 * @brief Concrete decorator that adds pot functionality to plants
 *
 * This decorator adds pot features to plants, including pot type and cost.
 * It extends the PlantDecorations base class to provide specific pot
 * decoration.
 */
class PotDecorator : public PlantDecorations {
private:
  string potType; ///< Type of pot being added
  double potCost; ///< Cost of the pot decoration

public:
  /**
   * @brief Constructor for PotDecorator
   * @param item The plant to decorate with a pot
   * @param pot The type of pot to add
   * @param cost The cost of the pot
   */
  PotDecorator(Plant *item, string pot, double cost);

  /**
   * @brief Gets the description including pot information
   * @return String description of the plant with pot
   */
  string description() override;

  /**
   * @brief Gets the total price including pot cost
   * @return Total price of plant plus pot
   */
  double price() override;

  /**
   * @brief Creates a clone of the pot-decorated plant
   * @return Pointer to cloned pot-decorated plant
   */
  Plant *clone() override;
};

#endif