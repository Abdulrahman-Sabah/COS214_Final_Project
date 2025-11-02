/**
 * @file CactusCreator.cpp
 * @brief Implementation of CactusCreator factory
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "CactusCreator.h"
#include "Cactus.h"
#include <iostream>

Plant *CactusCreator::factoryMethod() const {
  std::cout << "anOperation: CactusCreator has executed successfully."
            << std::endl;
  return new Cactus();
}
