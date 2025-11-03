#ifndef BASICPLANT_CPP_DOC
/**
 * @file BasicPlant.cpp
 * @brief Implementations for BasicPlant (simple concrete Plant).
 * @author Git it done group members
 * @date 10-2025
 */
#define BASICPLANT_CPP_DOC
#endif

#include "BasicPlant.h"

BasicPlant::BasicPlant(string name, string description, double price,
                       string careType, string state, string season)
    : Plant(name, careType, state, season, nullptr, nullptr), basePrice(price),
      plantDescription(description) {}

string BasicPlant::description() { return plantDescription; }

double BasicPlant::price() { return basePrice; }

Plant *BasicPlant::clone() { return new BasicPlant(*this); }