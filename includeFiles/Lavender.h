#ifndef LAVENDER_H
#define LAVENDER_H

#include "Plant.h"

class Lavender : public Plant {
public:
  Lavender();
  ~Lavender();
  std::string description() override;
  double price() override;
  Plant *clone() override;
};

#endif