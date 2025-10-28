#include "WrapDecorator.h"

WrapDecorator::WrapDecorator(Plant* item, string wrap, double cost) 
    : PlantDecorations(item), wrapType(wrap), wrapCost(cost) {}

string WrapDecorator::description() {
    return wrappedPlant->description() + " with " + wrapType + " wrap";
}

double WrapDecorator::price() {
    return wrappedPlant->price() + wrapCost;
}

Plant* WrapDecorator::clone() {
    return new WrapDecorator(wrappedPlant->clone(), wrapType, wrapCost);
}