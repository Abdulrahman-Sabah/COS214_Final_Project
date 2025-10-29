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
