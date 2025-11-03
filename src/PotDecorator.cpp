#ifndef POTDECORATOR_CPP_DOC
/**
 * @file PotDecorator.cpp
 * @brief Implementation of PotDecorator to add pot-related description & cost.
 * @author Git it done group members
 * @date 10-2025
 */
#define POTDECORATOR_CPP_DOC
#endif

#include "PotDecorator.h"

PotDecorator::PotDecorator(Plant *item, string pot, double cost)
    : PlantDecorations(item), potType(pot), potCost(cost) {}

string PotDecorator::description() {
  if (!wrappedPlant) {
    return " in pot: " + potType;
  }
  std::string res = wrappedPlant ? wrappedPlant->description() : "";
  return res + " in pot: " + potType;
}

double PotDecorator::price() {
  if (!wrappedPlant) {
    return potCost;
  }
  return wrappedPlant->price();
}

Plant *PotDecorator::clone() {
  return new PotDecorator(wrappedPlant->clone(), potType, potCost);
}