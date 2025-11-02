/**
 * @file GreenhouseManager.cpp
 * @brief Implementation of GreenhouseManager handler for sales operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "GreenhouseManager.h"
#include "Commands.h"
#include <iostream>
void GreenhouseManager::handleRequest(Commands *r) {
  if (r && r->getType() == "MoveToSales") {
    std::cout << "Greenhouse Manager is moving plants to sales area."
              << std::endl;
  } else {
    // Pass to next handler in chain using protected method
    passToSuccessor(r);
  }
}