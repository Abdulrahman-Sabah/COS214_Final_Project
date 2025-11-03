#ifndef GREENHOUSEMANAGER_CPP_DOC
/**
 * @file GreenhouseManager.cpp
 * @brief Concrete handler for sales/inventory management in the chain.
 * @author Git it done group members
 * @date 10-2025
 */
#define GREENHOUSEMANAGER_CPP_DOC
#endif

#include "GreenhouseManager.h"

#include <iostream>

#include "Commands.h"

void GreenhouseManager::handleRequest(Commands *r, Plant *plant) {
  if (!plant) {
    delete r;
    return;
  }
  if (r && (r->name() == "LavenderStrategy" || r->name() == "RoseStrategy" ||
            r->name() == "CactusStrategy")) {

    std::cout << "Greenhouse Manager: Executing " << r->name() << " on "
              << plant->getName() << ".\n";

    r->execute(plant);
    delete r;
  } else {
    // Pass to next handler in chain using protected method
    std::cout << "Greenhouse Manager: This request is not my responsibility. "
                 "My  responsibility is the Strategy(Rose, Cactus,Lavender)"
                 "Calling Landscaper...\n";
    passToSuccessor(r, plant);
  }
}