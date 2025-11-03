#ifndef CARDDECORATOR_CPP_DOC
/**
 * @file CardDecorator.cpp
 * @brief Implementation of the CardDecorator which adds card message & cost.
 * @author Git it done group members
 * @date 10-2025
 */
#define CARDDECORATOR_CPP_DOC
#endif

#include "CardDecorator.h"

CardDecorator::CardDecorator(Plant *item, string msg, double cost)
    : PlantDecorations(item), message(msg), cardCost(cost) {}

string CardDecorator::description() {
    std::string res = wrappedPlant ? wrappedPlant->description() : "";
    return res + " with card: \"" + message + "\"";
}

double CardDecorator::price() { return this->cardCost; }

Plant *CardDecorator::clone() {
  return new CardDecorator(wrappedPlant->clone(), message, cardCost);
}