#include "Lavender.h"
// #include "LavenderCare.h"     // Will be available after merging branches
// #include "Seedling.h"         // Will be available after merging branches

Lavender::Lavender() : Plant("Lavender", "Moderate", "Seedling", "Spring", nullptr, nullptr) {
    // TODO: When branches are merged, update to:
    // Plant("Lavender", "Moderate", "Seedling", "Spring", new LavenderCare(), new Seedling())
    
    // Lavender typically needs moderate care and starts as a seedling in spring
    
}

Lavender::~Lavender() {
    
}

Plant* Lavender::clone() {
    
    Lavender* clonedLavender = new Lavender();
    clonedLavender->setName(this->getName());
    clonedLavender->setCareType(this->getCareType());
    clonedLavender->setStateText(this->getStateText());
    clonedLavender->setSeason(this->getSeason());
    return clonedLavender;
}