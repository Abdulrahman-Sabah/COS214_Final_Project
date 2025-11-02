#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

/**
 * @file InventoryIterator.h
 * @brief Iterator implementation for Inventory collections.
 *
 * Provides a concrete PlantIterator that walks through a vector of Plant
 * pointers stored in Inventory-like aggregates.
 */

#include <vector>

#include "PlantIterator.h"

class InventoryIterator : public PlantIterator {
private:
  std::vector<Plant *> &plants;
  size_t currentIndex;

public:
  InventoryIterator(std::vector<Plant *> &plantList);

  ~InventoryIterator();

  void first() override;
  void next() override;
  bool isDone() override;
  Plant *current() override;
};

#endif
