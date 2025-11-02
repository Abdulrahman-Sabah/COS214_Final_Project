#ifndef BASICPLANT_H
#define BASICPLANT_H

/**
 * @file BasicPlant.h
 * @brief Concrete basic plant implementation used by the nursery.
 *
 * Provides a simple, concrete implementation of the Plant interface
 * with a base price and description. This file declares the
 * BasicPlant class used throughout the project.
 */

#include "Plant.h"

class BasicPlant : public Plant {
private:
  double basePrice;
  string plantDescription;

public:
  BasicPlant(string name, string description, double price,
             string careType = "Basic", string state = "Healthy",
             string season = "AllSeason");

  string description() override;
  double price() override;
  Plant *clone() override;
};

#endif