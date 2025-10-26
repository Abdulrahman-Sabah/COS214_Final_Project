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