#include "Rose.h"
#include <iostream>
// #include "RoseCare.h"     // Will be available after merging branches
// #include "Seedling.h"     // Will be available after merging branches

Rose::Rose()
    : Plant("Rose", "Moderate", "Seedling", "Spring", nullptr, nullptr)
{
    // TODO: When branches are merged, update to:
    // Plant("Rose", "Moderate", "Seedling", "Spring", new RoseCare(), new Seedling());
    // Roses typically need moderate care and start as seedlings in spring.
}

Plant* Rose::clone() {
    Rose* clonedRose = new Rose();
    clonedRose->setName(this->getName());
    clonedRose->setCareType(this->getCareType());
    clonedRose->setStateText(this->getStateText());
    clonedRose->setSeason(this->getSeason());
    clonedRose->setCareStrategy(this->getCareStrategy());
    clonedRose->setLifeCycle(this->getLifeCycle());
    return clonedRose;
}

std::string Rose::description() {
    return "Rose (Rosa): a fragrant and colorful flowering plant symbolizing love and beauty.";
}

double Rose::price() {
    return 79.99; 
}
