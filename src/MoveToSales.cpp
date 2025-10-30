#include "MoveToSales.h"

MoveToSales::MoveToSales(const std::string& id)
    : plantId(id) {}

std::string MoveToSales::getType() const {
    return "MoveToSales";
}

std::string MoveToSales::getData() const {
    return plantId;
}
