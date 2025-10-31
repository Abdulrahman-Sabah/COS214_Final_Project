#include "RoseCreator.h"

#include <iostream>

#include "Rose.h"

RoseCreator::RoseCreator() {}

Plant* RoseCreator::factoryMethod() const {
  std::cout << "anOperation: RoseCreator has executed successfully."
            << std::endl;
  return new Rose();
}
