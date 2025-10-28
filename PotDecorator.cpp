/**
 * @file PotDecorator.cpp
 * @brief Implementation of the PotDecorator class
 * @author COS214 Students
 * @date 2024
 */

#include "PotDecorator.h"

PotDecorator::PotDecorator(Plant* item, string pot, double cost) 
    : PlantDecorations(item), potType(pot), potCost(cost) {}

string PotDecorator::description() {
    return wrappedPlant->description() + " in " + potType + " pot";
}

double PotDecorator::price() {
    return wrappedPlant->price() + potCost;
}

Plant* PotDecorator::clone() {
    return new PotDecorator(wrappedPlant->clone(), potType, potCost);
}