
#ifndef CACTUS_H
#define CACTUS_H

/**
 * @file Cactus.h
 * @brief Declaration of the Cactus plant concrete class.
 *
 * Cactus is a concrete Plant used by the nursery. It provides a description,
 * price and clone implementation specific to cactus plants.
 */

#include "Plant.h"

class Cactus : public Plant {
public:
  Cactus();
  ~Cactus();
  std::string description() override;
  double price() override;
  Plant *clone() override;
  std::string getType() const override { return "Cactus"; }
};

#endif