#include "Cactus.h"
#include <iostream>
#include "CactusCare.h"     
#include "SeedlingState.h"       

Cactus::Cactus()
    : Plant("Cactus", "Low", "Seedling", "Summer", new CactusCare(), new SeedlingState())
{}

Plant* Cactus::clone() {
    Cactus* clonedCactus = new Cactus();
    clonedCactus->setName(this->getName());
    clonedCactus->setCareType(this->getCareType());
    clonedCactus->setStateText(this->getStateText());
    clonedCactus->setSeason(this->getSeason());
    clonedCactus->setCareStrategy(new CactusCare());
    clonedCactus->setLifeCycle(new SeedlingState());
    return clonedCactus;
}

std::string Cactus::description() {
    return "Cactus (Cactaceae): a hardy, water-efficient plant adapted to dry climates.";
}

double Cactus::price() 
{
    return 59.99; 
}



Cactus::~Cactus() 
{
    
}
