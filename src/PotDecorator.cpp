#include "PotDecorator.h"

PotDecorator::PotDecorator(Plant *item, string pot, double cost)
    : PlantDecorations(item), potType(pot), potCost(cost) {}

string PotDecorator::description() {
  return this->potType;
}

double PotDecorator::price() { return this->potCost; }

Plant *PotDecorator::clone() {
  return new PotDecorator(wrappedPlant->clone(), potType, potCost);
}