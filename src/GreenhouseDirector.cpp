#include "GreenhouseDirector.h"

#include "PlantBuilder.h"
#include "SeedlingState.h"

GreenhouseDirector::GreenhouseDirector(PlantBuilder* b) : builder(b) {}

void GreenhouseDirector::construct() {
  builder->setName();
  builder->setCareType("Low Watering");
  builder->setSeason("Summer");
  builder->setLifeCycle(new SeedlingState());
}