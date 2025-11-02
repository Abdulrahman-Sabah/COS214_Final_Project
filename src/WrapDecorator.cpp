#include "WrapDecorator.h"

WrapDecorator::WrapDecorator(Plant *item, string wrap, double cost)
    : PlantDecorations(item), wrapType(wrap), wrapCost(cost) {}

string WrapDecorator::description() {
  return this->wrapType;
}

double WrapDecorator::price() 
{
  return this->wrapCost; 
}

Plant *WrapDecorator::clone() 
{
  return new WrapDecorator(wrappedPlant->clone(), wrapType, wrapCost);
}