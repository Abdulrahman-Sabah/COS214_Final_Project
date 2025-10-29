#ifndef GREENHOUSE_DIRECTOR_H
#define GREENHOUSE_DIRECTOR_H

#include "PlantBuilder.h"

class GreenhouseDirector {
private:
  PlantBuilder *builder;

public:
  GreenhouseDirector(PlantBuilder *b);
  void construct();
};

#endif