#include "ApplyFertilizer.h"

ApplyFertilizer::ApplyFertilizer(const std::string& id)
    : plantId(id) {}

std::string ApplyFertilizer::getType() const {
    return "ApplyFertilizer";
}

std::string ApplyFertilizer::getData() const {
    return plantId;
}