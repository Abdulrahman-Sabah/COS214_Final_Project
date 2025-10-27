#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H
#include "Handler.h"
class DeliveryStaff : public Handler{
public:
    void handleRequest(Commands* r) override;
};

#endif