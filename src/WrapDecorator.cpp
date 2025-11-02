#include "WrapDecorator.h"

WrapDecorator::WrapDecorator(Plant *item, string wrap, double cost)
    : PlantDecorations(item), wrapType(wrap), wrapCost(cost) {}

string WrapDecorator::description() {
  if(!wrappedPlant) {
      return " with wrap: " + wrapType;
  }
  std::string res = wrappedPlant ? wrappedPlant->description() : "";
  return res + " with wrap: " + wrapType;
}

double WrapDecorator::price() 
{
  if(!wrappedPlant) {
      return wrapCost;
  }
  return wrappedPlant->price() + wrapCost;
}

Plant *WrapDecorator::clone() 
{
  return new WrapDecorator(wrappedPlant->clone(), wrapType, wrapCost);
}