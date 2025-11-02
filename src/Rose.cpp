
/**
 * @file Rose.cpp
 * @brief Implementation of the Rose class
 * @author COS214 Students
 * @date 2024
 */

#include "Rose.h"
#include "RoseCare.h"
#include "SeedlingState.h"
#include <iostream>

Rose::Rose()
    : Plant("Rose", "Moderate", "Seedling", "Spring", new RoseCare(),
            new SeedlingState()) {}

Plant *Rose::clone() {
  Rose *clonedRose = new Rose();
  clonedRose->setName(this->getName());
  clonedRose->setCareType(this->getCareType());
  clonedRose->setStateText(this->getStateText());
  clonedRose->setSeason(this->getSeason());
  clonedRose->setCareStrategy(this->getCareStrategy());
  clonedRose->setLifeCycle(this->getLifeCycle());
  return clonedRose;
}

std::string Rose::description() {
  return "Rose (Rosa): a fragrant and colorful flowering plant symbolizing "
         "love and beauty.";
}

double Rose::price() { return 79.99; }

Rose::~Rose() {}
