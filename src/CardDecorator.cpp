/**
 * @file CardDecorator.cpp
 * @brief Implementation of CardDecorator for adding greeting cards to plants
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "CardDecorator.h"

CardDecorator::CardDecorator(Plant *item, string msg, double cost)
    : PlantDecorations(item), message(msg), cardCost(cost) {}

string CardDecorator::description() {
  return wrappedPlant->description() + " with card: \"" + message + "\"";
}

double CardDecorator::price() { return wrappedPlant->price() + cardCost; }

Plant *CardDecorator::clone() {
  return new CardDecorator(wrappedPlant->clone(), message, cardCost);
}