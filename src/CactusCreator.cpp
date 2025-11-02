#ifndef CACTUSCREATOR_CPP_DOC
/**
 * @file CactusCreator.cpp
 * @brief Factory method implementation to create Cactus objects.
 */
#define CACTUSCREATOR_CPP_DOC
#endif

#include "CactusCreator.h"

#include <iostream>

#include "Cactus.h"

Plant *CactusCreator::factoryMethod() const {
  std::cout << "anOperation: CactusCreator has executed successfully."
            << std::endl;
  return new Cactus();
}
