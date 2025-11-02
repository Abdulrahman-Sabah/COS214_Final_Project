/**
 * @file Cactus.cpp
 * @brief Implementation of the Cactus class
 * @author COS214 Students
 * @date 2024
 */

#include "Cactus.h"
#include <iostream>
// #include "CactusCare.h"     // Will be available after merging branches
// #include "Seedling.h"       // Will be available after merging branches

Cactus::Cactus()
    : Plant("Cactus", "Low", "Seedling", "Summer", nullptr, nullptr) {
  // TODO: When branches are merged, update to:
  // Plant("Cactus", "Low", "Seedling", "Summer", new CactusCare(), new
  // Seedling()); Cactus typically needs low care and starts as a seedling in
  // summer.
}

Plant *Cactus::clone() {
  Cactus *clonedCactus = new Cactus();
  clonedCactus->setName(this->getName());
  clonedCactus->setCareType(this->getCareType());
  clonedCactus->setStateText(this->getStateText());
  clonedCactus->setSeason(this->getSeason());
  clonedCactus->setCareStrategy(this->getCareStrategy());
  clonedCactus->setLifeCycle(this->getLifeCycle());
  return clonedCactus;
}

std::string Cactus::description() {
  return "Cactus (Cactaceae): a hardy, water-efficient plant adapted to dry "
         "climates.";
}

double Cactus::price() { return 59.99; }

Cactus::~Cactus() {}
