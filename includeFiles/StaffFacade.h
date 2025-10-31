#ifndef STAFF_FACADE_H
#define STAFF_FACADE_H

#include <string>

#include "Inventory.h"

class StaffFacade {
 private:
  Inventory& inventory;

 public:
  explicit StaffFacade(Inventory& inv);
  void addStock(const std::string& name);
};

#endif