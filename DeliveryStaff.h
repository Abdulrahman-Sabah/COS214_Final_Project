/**
 * @file DeliveryStaff.h
 * @brief Delivery staff that interacts with the mediator and participates in the chain of responsibility
 * @author COS214
 * @date 2025
 */

#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include "Handler.h"
#include "StoreColleague.h"
#include "Commands.h"
#include <iostream>

class DeliveryStaff : public Handler, public StoreColleague {
public:
    using StoreColleague::StoreColleague;

    /**
     * @brief Handles delivery-related commands (part of Chain of Responsibility)
     */
    void handleRequest(Commands* r) override;

    /**
     * @brief Processes a request from the mediator (e.g., a customer order)
     */
    void processCustomerRequest(Commands* cmd);

    /**
     * @brief Receives notifications from mediator
     */
    void receive(const std::string& event) override;
};

#endif
