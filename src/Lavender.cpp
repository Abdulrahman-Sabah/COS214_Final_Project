#ifndef LAVENDER_CPP_DOC
/**
 * @file Lavender.cpp
 * @brief Concrete Lavender plant implementation.
 * @author Git it done group members
 * @date 10-2025
 */
#define LAVENDER_CPP_DOC
#endif

#include "Lavender.h"

#include <iostream>

#include "LavenderCare.h"
#include "SeedlingState.h"

// Constructor
Lavender::Lavender()
    : Plant("Lavender", "Moderate", "Seedling", "Spring", new LavenderCare(),
            new SeedlingState()) {}

Plant *Lavender::clone() {
  Lavender *clonedLavender = new Lavender();
  clonedLavender->setName(this->getName());
  clonedLavender->setCareType(this->getCareType());
  clonedLavender->setStateText(this->getStateText());
  clonedLavender->setSeason(this->getSeason());
  clonedLavender->setCareStrategy(new LavenderCare());
  clonedLavender->setLifeCycle(new SeedlingState());
  return clonedLavender;
}

std::string Lavender::description() {
  return "Lavender (Lavandula): a fragrant purple herb often used for "
         "decoration and scent.";
}

double Lavender::price() { return 49.99; }

Lavender::~Lavender() {}