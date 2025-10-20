#include "Cactus.h"
// #include "CactusCare.h"     // Will be available after merging branches
// #include "Seedling.h"       // Will be available after merging branches

Cactus::Cactus() : Plant("Cactus", "Low", "Seedling", "Summer", nullptr, nullptr) {
    // TODO: When branches are merged, update to:
    // Plant("Cactus", "Low", "Seedling", "Summer", new CactusCare(), new Seedling())
    
    // Cactus typically needs low care and starts as a seedling in summer
    
}

Cactus::~Cactus() {
    
}

Plant* Cactus::clone() {
    
    Cactus* clonedCactus = new Cactus();
    clonedCactus->setName(this->getName());
    clonedCactus->setCareType(this->getCareType());
    clonedCactus->setStateText(this->getStateText());
    clonedCactus->setSeason(this->getSeason());
    return clonedCactus;
}