#ifndef WRAPDECORATOR_H
#define WRAPDECORATOR_H

#include "PlantDecorations.h"

class WrapDecorator : public PlantDecorations {
private:
  string wrapType;
  double wrapCost;

public:
  WrapDecorator(Plant *item, string wrap, double cost);

  string description() override;
  double price() override;
  Plant *clone() override;
};

#endif