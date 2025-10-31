#include "GreenhouseManager.h"

#include <iostream>

#include "Commands.h"

void GreenhouseManager::handleRequest(Commands* r, Plant* plant) {
  if (r && (r->name() == "LavenderStrategy" || r->name() == "RoseStrategy" ||
            r->name() == "SucculentStrategy")) {
    std::cout << "Greenhouse Manager is moving plants is looking at the states "
                 "of the plnats"
              << std::endl;
    r->execute(plant);
  } else {
    // Pass to next handler in chain using protected method
    passToSuccessor(r, plant);
  }
}