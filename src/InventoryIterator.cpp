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
