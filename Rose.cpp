
#include "Rose.h"
#include <iostream>
#include "RoseCare.h"     
#include "SeedlingState.h"     

Rose::Rose()
    : Plant("Rose", "Moderate", "Seedling", "Spring", new RoseCare(), new Seedling())
{}

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

Rose::~Rose()
{
    
}
