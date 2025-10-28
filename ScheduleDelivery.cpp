/**
 * @file ScheduleDelivery.cpp
 * @brief Implementation of ScheduleDelivery command for delivery scheduling operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "ScheduleDelivery.h"

ScheduleDelivery::ScheduleDelivery(const std::string& id)
    : orderId(id) {}

std::string ScheduleDelivery::getType() const {
    return "ScheduleDelivery";
}

std::string ScheduleDelivery::getData() const {
    return orderId;
}
