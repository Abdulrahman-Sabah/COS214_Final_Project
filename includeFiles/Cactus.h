
#ifndef CACTUS_H
#define CACTUS_H

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