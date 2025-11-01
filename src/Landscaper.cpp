/**
 * @file Landscaper.cpp
 * @brief Implementation of Landscaper handler for plant care operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "Landscaper.h"

#include <iostream>

#include "Commands.h"

void Landscaper::handleRequest(Commands *r, Plant *plant) {
  if (!plant)
    return;
  if (r && (r->name() == "SeedlingState" || r->name() == "GrowingState" ||
            r->name() == "DormantState" || r->name() == "MatureState" ||
            r->name() == "SellingState" || r->name() == "DeadState")) {
    std::cout << "Landscaper: Executing " << r->name() << " on "
              << plant->getName() << ".\n";
    r->execute(plant);
    delete r;
  } else {
    std::cout << "Landscaper: This request is not my responsibility. My "
                 "responsibility are the "
                 "sates(Seedling,Growing,Dormant,Mature,Selling,Dead) "
                 "No further handlers available.\n";
    passToSuccessor(r, plant);
  }
}