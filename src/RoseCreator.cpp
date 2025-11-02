/**
 * @file RoseCreator.cpp
 * @brief Implementation of the RoseCreator class
 * @author COS214 Students
 * @date 2024
 */

#include "RoseCreator.h"
#include "Rose.h"
#include <iostream>

RoseCreator::RoseCreator() {}

Plant *RoseCreator::factoryMethod() const {
  std::cout << "anOperation: RoseCreator has executed successfully."
            << std::endl;
  return new Rose();
}
