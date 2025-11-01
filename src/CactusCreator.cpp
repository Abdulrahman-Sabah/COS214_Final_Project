#include "CactusCreator.h"

#include <iostream>

#include "Cactus.h"

Plant *CactusCreator::factoryMethod() const {
  std::cout << "anOperation: CactusCreator has executed successfully."
            << std::endl;
  return new Cactus();
}
