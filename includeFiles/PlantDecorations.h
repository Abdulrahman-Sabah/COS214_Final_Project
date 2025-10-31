#ifndef PLANTDECORATIONS_H
#define PLANTDECORATIONS_H

#include <string>

#include "Plant.h"

using namespace std;

class PlantDecorations : public Plant {
 protected:
  Plant* wrappedPlant;

 public:
  PlantDecorations(Plant* item);
  virtual ~PlantDecorations();
  string getName() override { return wrappedPlant->getName(); }
  virtual string description() = 0;
  virtual double price() = 0;
  virtual Plant* clone() = 0;
};

#endif