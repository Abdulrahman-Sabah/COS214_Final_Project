/**
 * @file RoseCare.cpp
 * @brief Implementation of the RoseCare class
 * @author COS214 Students
 * @date 2024
 */

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
