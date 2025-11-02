#ifndef LAVENDER_H
#define LAVENDER_H

/**
 * @file Lavender.h
 * @brief Declaration of the Lavender plant concrete class.
 */

#include "Plant.h"

class Lavender : public Plant {
public:
  Lavender();
  ~Lavender();

  /** @brief Returns textual description of the lavender */
  std::string description() override;

  /** @brief Returns price for lavender */
  double price() override;

  /** @brief Clone a Lavender instance */
  Plant *clone() override;

  std::string getType() const override { return "Lavender"; }
};

#endif