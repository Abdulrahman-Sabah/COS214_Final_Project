#ifndef ROSECREATOR_CPP_DOC
/**
 * @file RoseCreator.cpp
 * @brief Factory method to create Rose instances.
 */
#define ROSECREATOR_CPP_DOC
#endif

#include "RoseCreator.h"

#include <iostream>

#include "Rose.h"

RoseCreator::RoseCreator() {}

Plant *RoseCreator::factoryMethod() const {
  std::cout << "anOperation: RoseCreator has executed successfully."
            << std::endl;
  return new Rose();
}
