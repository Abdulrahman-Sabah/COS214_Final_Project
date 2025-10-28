/**
 * @file FrontDesk.h
 * @brief Concrete mediator coordinating between StoreCustomer and DeliveryStaff in the nursery system
 * @author COS214
 * @date 2025
 */

#ifndef FRONTDESK_H
#define FRONTDESK_H

#include "StoreMediator.h"

class StoreCustomer;
class DeliveryStaff;
class Handler;
class Commands;

class FrontDesk : public StoreMediator {
private:
    StoreCustomer* customer;
    DeliveryStaff* staff;
    Handler* handlerChain;

public:
    FrontDesk(StoreCustomer* c, DeliveryStaff*, Handler* chain);
    void setCustomer(StoreCustomer* c);
    void setDeliveryStaff(DeliveryStaff* d);
    void setHandlerChain(Handler* chain);

    /**
     * @brief Handles communication between participants
     */
    void notify(void* sender, const std::string& event, Commands* cmd = nullptr) override;
};

#endif
