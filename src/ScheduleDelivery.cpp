#include "ScheduleDelivery.h"

ScheduleDelivery::ScheduleDelivery(const std::string& id)
    : orderId(id) {}

std::string ScheduleDelivery::getType() const {
    return "ScheduleDelivery";
}

std::string ScheduleDelivery::getData() const {
    return orderId;
}
