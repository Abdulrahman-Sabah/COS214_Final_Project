/**
 * @file DeliveryStaff.h
 * @brief Handles delivery of plants to customers.
 */

#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

#include <iostream>
#include "Inventory.h"
#include "Plant.h"
#include "StoreColleague.h"

/**
 * @class DeliveryStaff
 * @brief Delivery role in the nursery.
 */
class DeliveryStaff : public StoreColleague {
private:
    Inventory* greenhouse_;

public:
    /// Default constructor
    DeliveryStaff() : greenhouse_(nullptr) {}

    /// @param inv Inventory pointer
    explicit DeliveryStaff(Inventory* inv) : greenhouse_(inv) {}

    /// Virtual destructor
    ~DeliveryStaff() override = default;

    /**
     * @brief Set greenhouse inventory
     * @param inv Inventory pointer
     */
    void setInventory(Inventory* inv) { greenhouse_ = inv; }

    /**
     * @brief Deliver a requested plant
     * @param plant Plant to deliver
     */
    void processCustomerRequest(Plant* plant);

    /**
     * @brief Receive notifications
     * @param event Text message about an update
     */
    void receive(const std::string& event) override;
};

#endif // DELIVERYSTAFF_H
