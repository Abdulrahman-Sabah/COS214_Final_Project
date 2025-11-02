#ifndef POTDECORATOR_H
#define POTDECORATOR_H

/**
 * @file PotDecorator.h
 * @brief Decorator that adds a pot type and cost to a Plant.
 */

#include "PlantDecorations.h"

class PotDecorator : public PlantDecorations {
private:
  string potType; /**< Type of pot used */
  double potCost; /**< Additional cost for the pot */

public:
  /** @brief Create a PotDecorator wrapping a Plant */
  PotDecorator(Plant *item, string pot, double cost);

  string description() override;
  double price() override;
  Plant *clone() override;
};

#endif