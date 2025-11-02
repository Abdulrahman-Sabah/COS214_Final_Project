/**
 * @file Lavender.cpp
 * @brief Implementation of the Lavender class
 * @author COS214 Students
 * @date 2024
 */

#include "Lavender.h"
#include <iostream>

// Constructor
Lavender::Lavender()
    : Plant("Lavender", "Moderate", "Seedling", "Spring", nullptr, nullptr) {
  // Later, after merging branches:
  // Plant("Lavender", "Moderate", "Seedling", "Spring", new LavenderCare(), new
  // Seedling()); For now, we just use nullptr placeholders for care strategy
  // and life cycle.
}

Plant *Lavender::clone() {
  Lavender *clonedLavender = new Lavender();
  clonedLavender->setName(this->getName());
  clonedLavender->setCareType(this->getCareType());
  clonedLavender->setStateText(this->getStateText());
  clonedLavender->setSeason(this->getSeason());
  clonedLavender->setCareStrategy(this->getCareStrategy());
  clonedLavender->setLifeCycle(this->getLifeCycle());
  return clonedLavender;
}

std::string Lavender::description() {
  return "Lavender (Lavandula): a fragrant purple herb often used for "
         "decoration and scent.";
}

double Lavender::price() { return 49.99; }

Lavender::~Lavender() {}