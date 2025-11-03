#ifndef ROSECARE_CPP_DOC
/**
 * @file RoseCare.cpp
 * @brief Rose-specific CareStrategy implementation.
 * @author Git it done group members
 * @date 10-2025
 */
#define ROSECARE_CPP_DOC
#endif

#include "RoseCare.h"

#include "Plant.h"

void RoseCare::applyCare(Plant *plant) {
  std::cout
      << plant->getName()
      << " is being watered regularly to keep the soil consistently moist."
      << std::endl;
  std::cout << plant->getName()
            << " is now being pruned to remove dead or weak stems."
            << std::endl;
  std::cout << plant->getName() << " is being fertilized for best blooms."
            << std::endl;
}
