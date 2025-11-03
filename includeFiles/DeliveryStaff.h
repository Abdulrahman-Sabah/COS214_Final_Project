
#ifndef DELIVERYSTAFF_H
#define DELIVERYSTAFF_H

/**
 * @file DeliveryStaff.h
 * @brief It defines the DeliveryStaff class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <iostream>
#include "Inventory.h"
#include "Plant.h"
#include "StoreColleague.h"

/**
 * @class DeliveryStaff
 * @brief Delivery role in the nursery.
 * @details Inherits from StoreColleague and manages plant deliveries from the greenhouse inventory.
 */
class DeliveryStaff : public StoreColleague {
private:
    /**
     * @brief Greenhouse inventory pointer
     */
    Inventory* greenhouse_;

public:
    /**
     * @brief Default constructor
     */
    DeliveryStaff() : greenhouse_(nullptr) {}

    /**
     * @brief Parameterized constructor
     * @param inv Inventory pointer
     */
    explicit DeliveryStaff(Inventory* inv) : greenhouse_(inv) {}

    /**
     * @brief Virtual destructor
     */
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
