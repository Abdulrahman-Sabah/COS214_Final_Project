#include "InventoryAggregate.h"

InventoryAggregate::InventoryAggregate() {}

InventoryAggregate::~InventoryAggregate() {
  for (Plant *p : plants) {
    delete p;
  }
  plants.clear();
}

size_t InventoryAggregate::getSize() const { return plants.size(); }

std::vector<Plant *> &InventoryAggregate::getPlants() { return plants; }
