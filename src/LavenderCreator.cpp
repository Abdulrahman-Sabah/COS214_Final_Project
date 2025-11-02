#include "LavenderCreator.h"

#include <iostream>

#include "Lavender.h"

LavenderCreator::LavenderCreator() {}

Plant *LavenderCreator::factoryMethod() const {
  std::cout << "anOperation: LavenderCreator has executed successfully."
            << std::endl;
  return new Lavender();
}
