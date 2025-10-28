/**
 * @file PlantLifeCycleState.cpp
 * @brief Implementation of the PlantLifeCycleState base class
 * @author COS214 Students
 * @date 2024
 */

#include "PlantLifeCycleState.h"

bool PlantLifeCycleState::getDead() {
    return dead;
}

bool PlantLifeCycleState::getAttention() {
    return attention;
}

bool PlantLifeCycleState::setDead(bool d) {
    dead = d;
    return dead;
}

bool PlantLifeCycleState::setAttention(bool a) {
    attention = a;
    return attention;
}
