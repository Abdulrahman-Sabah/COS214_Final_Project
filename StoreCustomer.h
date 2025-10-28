/**
 * @file StoreCustomer.h
 * @brief Represents a StoreCustomer interacting with the nursery via the mediator pattern
 * @author COS214
 * @date 2025
 */

#ifndef STORECUSTOMER_H
#define STORECUSTOMER_H

#include "StoreColleague.h"
#include "Commands.h"
#include <iostream>

class StoreCustomer : public StoreColleague {
public:
    using StoreColleague::StoreColleague;

    /**
     * @brief Sends a plant request to the mediator
     */
    void requestPlant(const std::string& plantName);

    /**
     * @brief Called when notified by the mediator (e.g., when the plant is ready)
     */
    void receive(const std::string& event) override;
};

#endif
