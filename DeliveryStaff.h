#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H
#include "Handler.h"
class DeliveryStaff : public Handler{
    void handleRequest(Command* r);
};

#endif