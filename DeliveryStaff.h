#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H
#include "Handler.h"
class DeliveryStaff : public Handler{
public:
    void handleRequest(Command* r) override;
};

#endif