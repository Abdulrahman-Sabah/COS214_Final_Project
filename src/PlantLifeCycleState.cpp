#ifndef PLANTLIFECYCLESTATE_CPP_DOC
/**
 * @file PlantLifeCycleState.cpp
 * @brief Base implementations for plant lifecycle state helpers.
 * @author Git it done group members
 * @date 10-2025
 */
#define PLANTLIFECYCLESTATE_CPP_DOC
#endif

#include "PlantLifeCycleState.h"

PlantLifeCycleState::PlantLifeCycleState() : dead(false), attention(false) {}

bool PlantLifeCycleState::getDead() { return dead; }

bool PlantLifeCycleState::getAttention() { return attention; }

bool PlantLifeCycleState::setDead(bool d) {
  dead = d;
  return dead;
}

bool PlantLifeCycleState::setAttention(bool a) {
  attention = a;
  return attention;
}
