#include "CactusCare.h"

#include "Plant.h"

void CactusCare::applyCare(Plant* plant) {
  std::cout << plant->getName()
            << " is being watered as soon as the soil is completely dry."
            << std::endl;
  std::cout << plant->getName() << " is now being placed in direct sunlight."
            << std::endl;
  std::cout
      << plant->getName()
      << " is being potted in a cactus-specific soil mix for optimal drainage."
      << std::endl;
}
