#include "PotDecorator.h"

PotDecorator::PotDecorator(Plant* item, string pot, double cost) 
    : PlantDecorations(item), potType(pot), potCost(cost) {
}

string PotDecorator::description() {
    return wrappedPlant->description() + " in " + potType + " pot";
}

double PotDecorator::price() {
    // Delegate to wrapped plant and add pot cost
    return wrappedPlant->price() + potCost;
}

Plant* PotDecorator::clone() {
    return new PotDecorator(wrappedPlant->clone(), potType, potCost);
}