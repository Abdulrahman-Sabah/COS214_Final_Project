
#include "Rose.h"
#include "CareStrategy.h"
#include "PlantLifeCycleState.h"
#include <iostream>

Rose::Rose() : Plant("Rose", "Moderate", "Seedling", "Spring", nullptr, nullptr) {
    std::cout << "Rose created: " << getName() << std::endl;
}

Rose::~Rose() {
    std::cout << "Rose destroyed: " << getName() << std::endl;
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
string Rose::description() {
    return "Beautiful Rose plant with fragrant blooms. Care Type: " + 
           getCareType() + ", Current State: " + getStateText() + 
           ", Season: " + getSeason();
}

double Rose::price() {
    double basePrice = 25.00;
    if (getStateText() == "Seedling") {
        basePrice = 15.00;
    } else if (getStateText() == "Flowering") {
        basePrice = 45.00;
    } else if (getStateText() == "Mature") {
        basePrice = 35.00;
    }
    
    return basePrice;
}
