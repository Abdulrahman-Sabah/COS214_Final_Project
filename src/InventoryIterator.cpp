#ifndef INVENTORYITERATOR_CPP_DOC
/**
 * @file InventoryIterator.cpp
 * @brief Concrete iterator for Inventory collections.
 */
#define INVENTORYITERATOR_CPP_DOC
#endif

#include "InventoryIterator.h"

InventoryIterator::InventoryIterator(std::vector<Plant *> &plantList)
    : plants(plantList), currentIndex(0) {}

InventoryIterator::~InventoryIterator() {}

void InventoryIterator::first() { currentIndex = 0; }

void InventoryIterator::next() {
  if (!isDone()) {
    currentIndex++;
  }
}

bool InventoryIterator::isDone() { return currentIndex >= plants.size(); }

Plant *InventoryIterator::current() {
  if (isDone()) {
    return nullptr;
  }
  return plants[currentIndex];
}
