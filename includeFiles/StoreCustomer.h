/**
 * @file StoreCustomer.h
 * @brief Customer interacting with the store via mediator.
 */

#ifndef STORECUSTOMER_H
#define STORECUSTOMER_H

#include <iostream>
#include "Commands.h"
#include "Plant.h"
#include "StoreColleague.h"

/**
 * @class StoreCustomer
 * @brief Represents a customer requesting plants.
 */
class StoreCustomer : public StoreColleague {
public:
    using StoreColleague::StoreColleague;
    StoreCustomer() = default;
    ~StoreCustomer() override = default;

    /**
     * @brief Send request by plant name
     * @param plantName Name of plant
     */
    void requestPlant(const std::string& plantName);

    /**
     * @brief Send request by plant pointer
     * @param p Plant pointer
     */
    void requestPlant(Plant* p);

    /**
     * @brief Receive notification from mediator
     * @param event Event text
     */
    void receive(const std::string& event) override;
};

#endif // STORECUSTOMER_H
