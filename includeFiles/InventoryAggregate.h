#ifndef INVENTORYAGGREGATE_H
#define INVENTORYAGGREGATE_H

#include <vector>

#include "Plant.h"
#include "PlantIterator.h"

class InventoryAggregate {
 protected:
  std::vector<Plant*> plants;

 public:
  InventoryAggregate();
  virtual ~InventoryAggregate();
  virtual void addPlant(Plant* p) = 0;
  virtual bool removePlant(Plant* p) = 0;
  virtual Plant* removePlantByName(const std::string& name) = 0;
  size_t getSize() const;
  virtual PlantIterator* createIterator() = 0;
  std::vector<Plant*>& getPlants();
  virtual void displayAll() = 0;
};

#endif
