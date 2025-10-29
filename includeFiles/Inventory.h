#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryAggregate.h"
#include "Plant.h"
#include "PlantIterator.h"
#include <vector>

class Inventory : public InventoryAggregate {
public:
  Inventory();
  ~Inventory();
  void addPlant(Plant *p);
  bool removePlant(Plant *p);
  Plant *removePlantByName(const std::string &name);
  size_t getSize() const;
  PlantIterator *createIterator();
  std::vector<Plant *> &getPlants();
  void displayAll();
};

#endif
