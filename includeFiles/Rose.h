

#ifndef ROSE_H
#define ROSE_H

/**
 * @file Rose.h
 * @brief Declaration of the Rose plant concrete class.
 */

#include "Plant.h"

class Rose : public Plant {
public:
  Rose();
  ~Rose();

  std::string description() override;
  double price() override;
  Plant *clone() override;
  std::string getType() const override { return "Rose"; }
};

#endif