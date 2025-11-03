#ifndef WRAPDECORATOR_CPP_DOC
/**
 * @file WrapDecorator.cpp
 * @brief Concrete decorator that adds wrapping and its cost to a Plant.
 * @author Git it done group members
 * @date 10-2025
 */
#define WRAPDECORATOR_CPP_DOC
#endif

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
  return wrappedPlant->price();
}

Plant *WrapDecorator::clone() 
{
  return new WrapDecorator(wrappedPlant->clone(), wrapType, wrapCost);
}