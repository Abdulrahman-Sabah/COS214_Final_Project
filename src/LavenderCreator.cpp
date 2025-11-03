#ifndef LAVENDERCREATOR_CPP_DOC
/**
 * @file LavenderCreator.cpp
 * @brief Factory method implementation to create Lavender objects.
 * @author Git it done group members
 * @date 10-2025
 */
#define LAVENDERCREATOR_CPP_DOC
#endif

#include "LavenderCreator.h"

#include <iostream>

#include "Lavender.h"

LavenderCreator::LavenderCreator() {}

Plant *LavenderCreator::factoryMethod() const {
  std::cout << "anOperation: LavenderCreator has executed successfully."
            << std::endl;
  return new Lavender();
}
