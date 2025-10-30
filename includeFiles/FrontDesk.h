#ifndef FRONTDESK_H
#define FRONTDESK_H

#include "StoreMediator.h"
#include <string>

class StoreCustomer;
class DeliveryStaff;
class Plant;

class FrontDesk : public StoreMediator {
public:
    FrontDesk(StoreCustomer* c = nullptr, DeliveryStaff* d = nullptr)
        : customer(c), staff(d) {}

    void setCustomer(StoreCustomer* c);
    void setDeliveryStaff(DeliveryStaff* d);

    void notify(Plant* plant, const std::string& event) override;

private:
    StoreCustomer* customer = nullptr;
    DeliveryStaff* staff    = nullptr;
};

#endif