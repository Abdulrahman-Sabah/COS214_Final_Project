#ifndef INVENTORYAGGREGATE_CPP_DOC
/**
 * @file InventoryAggregate.cpp
 * @brief Abstract aggregate implementation helpers.
 * @author Git it done group members
 * @date 10-2025
 */
#define INVENTORYAGGREGATE_CPP_DOC
#endif

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
