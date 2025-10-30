
#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include "Inventory.h"
#include "Plant.h"
#include "StoreColleague.h"
#include <iostream>

class DeliveryStaff : public StoreColleague {
private:
  Inventory *greenhouse_ = nullptr;

public:
  explicit DeliveryStaff(Inventory *inv) : greenhouse_(inv) {}

  void setInventory(Inventory *inv) { greenhouse_ = inv; }

  void processCustomerRequest(Plant *plant);
  void receive(const std::string &event) override;
};

#endif
