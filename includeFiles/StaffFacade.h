#ifndef STAFF_FACADE_H
#define STAFF_FACADE_H

#include "Inventory.h"
#include <string>

class StaffFacade {
private:
  Inventory &inventory;

public:
  explicit StaffFacade(Inventory &inv);
  void addStock(const std::string &name);
};

#endif