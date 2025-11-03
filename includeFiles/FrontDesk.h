/**
 * @file FrontDesk.h
 * @brief Mediator linking customers and delivery staff.
 */

#ifndef FRONTDESK_H
#define FRONTDESK_H

#include <string>
#include "StoreMediator.h"

class StoreCustomer;
class DeliveryStaff;
class Plant;

/**
 * @class FrontDesk
 * @brief Mediator for staff–customer communication.
 */
class FrontDesk : public StoreMediator {
public:
    /**
     * @brief Construct mediator
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
    StoreCustomer* customer = nullptr;
    DeliveryStaff* staff = nullptr;
};

#endif // FRONTDESK_H
