#ifndef INVENTORY_H
#define INVENTORY_H

/**
 * @file Inventory.h
 * @brief Collection and management of Plant objects.
 *
 * Inventory provides storage, search, add/remove and iterator support for
 * Plant instances used in the nursery application.
 */

#include <vector>

#include "Plant.h"
#include "PlantIterator.h"

class Inventory {
private:
  std::vector<Plant *> plants;

public:
  void clear() {
    for (Plant *plant : plants) {
      delete plant;
    }
    plants.clear();
  }

  Inventory();
  ~Inventory();
  void addPlant(Plant *p);
  bool removePlant(Plant *p);
  bool removePlantByName(const std::string &name);
  size_t getSize() const;
  PlantIterator *createIterator();
  std::vector<Plant *> &getPlants();
  void displayAll();
  bool hasPlant(Plant *p);
  Plant *at(int index) const;
};

#endif
