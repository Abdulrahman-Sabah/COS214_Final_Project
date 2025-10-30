/**
 * @file BasicPlant.cpp
 * @brief Implementation of BasicPlant class
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "BasicPlant.h"

BasicPlant::BasicPlant(string name, string description, double price, 
                       string careType, string state, string season)
    : Plant(name, careType, state, season, nullptr, nullptr), 
      basePrice(price), plantDescription(description) {}

string BasicPlant::description() {
    return plantDescription;
}

double BasicPlant::price() {
    return basePrice;
}

Plant* BasicPlant::clone() {
    return new BasicPlant(*this);
}