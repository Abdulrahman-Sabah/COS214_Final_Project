/**
 * @file Inventory.cpp
 * @brief Implementation of the Inventory class
 * @author COS214 Students
 * @date 2024
 */

#include "Inventory.h"
#include "InventoryIterator.h"
#include <algorithm>
#include <iostream>

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
  auto it = std::find(plants.begin(), plants.end(), p);
  if (it != plants.end()) {
    delete *it;
    plants.erase(it);
    return true;
  }
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
