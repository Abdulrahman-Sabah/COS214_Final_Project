/**
 * @file MoveToSales.cpp
 * @brief Implementation of MoveToSales command for plant sales operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "MoveToSales.h"

MoveToSales::MoveToSales(const std::string& id)
    : plantId(id) {}

std::string MoveToSales::getType() const {
    return "MoveToSales";
}

std::string MoveToSales::getData() const {
    return plantId;
}
