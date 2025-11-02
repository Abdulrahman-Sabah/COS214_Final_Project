#include "GreenhouseManager.h"

#include <iostream>

#include "Commands.h"

void GreenhouseManager::handleRequest(Commands *r, Plant *plant) {
  if (!plant)
    return;
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