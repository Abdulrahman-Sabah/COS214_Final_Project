/**
 * @file AddWater.cpp
 * @brief Implementation of AddWater command for plant watering operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "AddWater.h"

AddWater::AddWater(const std::string& id)
    : plantId(id) {}

std::string AddWater::getType() const 
{
    return "AddWater";
}

std::string AddWater::getData() const 
{
    return plantId;
}
