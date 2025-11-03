
#ifndef FRONTDESK_H
#define FRONTDESK_H

/**
 * @file FrontDesk.h
 * @brief It defines the FrontDesk class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>
#include "StoreMediator.h"

class StoreCustomer;
class DeliveryStaff;
class Plant;

/**
 * @class FrontDesk
 * @brief Mediator for staff–customer communication.
 * @details Inherits from StoreMediator and  allows communication between StoreCustomer and DeliveryStaff.
 */
class FrontDesk : public StoreMediator {
public:
    /**
     * @brief Parameterized constructor
     * @param c Customer
     * @param d Delivery staff
     */
    FrontDesk(StoreCustomer* c = nullptr, DeliveryStaff* d = nullptr)
        : customer(c), staff(d) {}

    /**
     * @brief Set customer
     * @param c StoreCustomer pointer
     */
    void setCustomer(StoreCustomer* c);

    /**
     * @brief Set delivery staff
     * @param d DeliveryStaff pointer
     */
    void setDeliveryStaff(DeliveryStaff* d);

    /**
     * @brief Send event notification
     * @param plant Plant involved
     * @param event Info message
     */
    void notify(Plant* plant, const std::string& event) override;

    /**
     * @brief Send information by plant type
     * @param type Plant type name
     */
    void infoByType(const std::string& type) const;

private:
    /**
     * @brief Customer associated with the front desk
     */
    StoreCustomer* customer = nullptr;

    /**
     * @brief Delivery staff associated with the front desk
     */
    DeliveryStaff* staff = nullptr;
};

#endif // FRONTDESK_H
