/**
 * @file ApplyFertilizer.cpp
 * @brief Implementation of ApplyFertilizer command for plant fertilization operations
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "ApplyFertilizer.h"

ApplyFertilizer::ApplyFertilizer(const std::string& id)
    : plantId(id) {}

std::string ApplyFertilizer::getType() const {
    return "ApplyFertilizer";
}

std::string ApplyFertilizer::getData() const {
    return plantId;
}
