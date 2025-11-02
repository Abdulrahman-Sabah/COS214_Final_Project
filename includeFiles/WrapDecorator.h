#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

/**
 * @file WrapDecorator.h
 * @brief Decorator that adds wrapping/packaging details to a Plant.
 */

#include "PlantDecorations.h"

class WrapDecorator : public PlantDecorations {
private:
  string wrapType; /**< Type of wrap used */
  double wrapCost; /**< Additional cost for wrapping */

public:
  /** @brief Create a wrap decorator wrapping the provided plant */
  WrapDecorator(Plant *item, string wrap, double cost);

  string description() override;
  double price() override;
  Plant *clone() override;
};

#endif