/**
 * @file ScheduleDelivery.h
 * @brief Concrete command for scheduling delivery operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef SCHEDULEDELIVERY_H
#define SCHEDULEDELIVERY_H

#include "Commands.h"
#include <string>

/**
 * @class ScheduleDelivery
 * @brief Concrete command implementation for scheduling plant deliveries
 * 
 * This class implements the Command pattern for delivery scheduling operations.
 * It encapsulates all the information needed to schedule a delivery, including
 * the order ID and any delivery-specific parameters.
 */
class ScheduleDelivery : public Commands {
private:
    std::string orderId; /**< Unique identifier for the delivery order */

public:
    /**
     * @brief Constructs a ScheduleDelivery command with the specified order ID
     * @param id The unique order identifier for the delivery
     */
    explicit ScheduleDelivery(const std::string& id);
    
    /**
     * @brief Gets the command type
     * @return String "ScheduleDelivery" identifying this command type
     */
    std::string getType() const override;
    
    /**
     * @brief Gets the order ID associated with this delivery command
     * @return String containing the order ID
     */
    std::string getData() const override;
};

#endif 
