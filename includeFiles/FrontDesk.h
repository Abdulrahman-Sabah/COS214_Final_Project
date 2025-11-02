#ifndef FRONTDESK_H
#define FRONTDESK_H

#include <string>

#include "StoreMediator.h"

class StoreCustomer;
class DeliveryStaff;
class Plant;

class FrontDesk : public StoreMediator {
public:
  FrontDesk(StoreCustomer *c = nullptr, DeliveryStaff *d = nullptr)
      : customer(c), staff(d) {}

  void setCustomer(StoreCustomer *c);
  void setDeliveryStaff(DeliveryStaff *d);

  void notify(Plant *plant, const std::string &event) override;
  void infoByType(const std::string& type) const;

private:
  StoreCustomer *customer = nullptr;
  DeliveryStaff *staff = nullptr;
};

#endif