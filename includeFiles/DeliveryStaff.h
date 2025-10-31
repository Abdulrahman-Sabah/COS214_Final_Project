
#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include <iostream>

#include "Inventory.h"
#include "Plant.h"
#include "StoreColleague.h"

class DeliveryStaff : public StoreColleague {
private:
  Inventory *greenhouse_;

public:
  DeliveryStaff() { greenhouse_ = nullptr; };
  ~DeliveryStaff() override = default;
  explicit DeliveryStaff(Inventory *inv) : greenhouse_(inv) {}

  void setInventory(Inventory* inv) { greenhouse_ = inv; }

  void processCustomerRequest(Plant* plant);
  void receive(const std::string& event) override;
};

#endif
