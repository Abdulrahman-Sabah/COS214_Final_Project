/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class
 * @author COS214 Students
 * @date 2024
 */

#ifndef INVENTORY_CPP_DOC
/**
 * @file Inventory.cpp
 * @brief Inventory container implementation for Plant objects.
 * @author Git it done group members
 * @date 10-2025
 */
#define INVENTORY_CPP_DOC
#endif

#include "Inventory.h"

#include <algorithm>
#include <iostream>

#include "InventoryIterator.h"
#include "PlantLifeCycleState.h"

Inventory::Inventory() {}

Inventory::~Inventory() {
  for (Plant *p : plants) {
    delete p;
  }
  plants.clear();
}

void Inventory::addPlant(Plant *p) {
  if (p != nullptr) {
    plants.push_back(p);
  }
}

bool Inventory::removePlant(Plant *p) {
  if (p == NULL) {
    return false;
  }

  PlantLifeCycleState *state = p->getLifeCycle();

  if (state == NULL || !state->isDead()) {
    std::cout << " Cannot remove: Plant is not dead.\n";
    return false;
  }

  for (std::vector<Plant *>::iterator it = plants.begin(); it != plants.end();
       ++it) {
    if (*it == p) {
      plants.erase(it);
      std::cout << " Dead plant removed from inventory.\n";
      return true;
    }
  }

  std::cout << " Plant not found in inventory.\n";
  return false;
}

bool Inventory::removePlantByName(const std::string &name) {
  for (auto it = plants.begin(); it != plants.end(); ++it) {
    if ((*it)->getName() == name) {
      delete *it;
      plants.erase(it);
      return true;
    }
  }
  return false;
}

size_t Inventory::getSize() const { return plants.size(); }

PlantIterator *Inventory::createIterator() {
  return new InventoryIterator(plants);
}

std::vector<Plant *> &Inventory::getPlants() { return plants; }

void Inventory::displayAll() {
  std::cout << "\nCurrent Inventory: \n";
  std::cout << "Total plants: " << plants.size() << "\n\n";

  PlantIterator *it = createIterator();
  int count = 1;

  for (it->first(); !it->isDone(); it->next()) {
    Plant *p = it->current();
    if (p != nullptr) {
      std::cout << count++ << ". ";
      // p->show();
      std::cout << "\n";
    }
  }

  delete it;
}

bool Inventory::hasPlant(Plant *p) {
  return std::find(plants.begin(), plants.end(), p) != plants.end();
}

Plant *Inventory::at(int index) const {
  if (index >= 0 && index < (int)plants.size())
    return plants[index];
  return NULL;
}
