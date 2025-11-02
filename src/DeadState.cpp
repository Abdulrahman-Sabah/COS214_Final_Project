#ifndef DEADSTATE_CPP_DOC
/**
 * @file DeadState.cpp
 * @brief Implementation of the Dead lifecycle state.
 */
#define DEADSTATE_CPP_DOC
#endif

#include "DeadState.h"

DeadState::DeadState() : PlantLifeCycleState() {}

DeadState::~DeadState() = default;

void DeadState::advance(Plant *plant) {
  std::cout << plant->getName() << " is dead." << std::endl;
}

std::string DeadState::name() { return "Dead"; }

bool DeadState::isDead() { return true; }

bool DeadState::needsAttention() { return false; }
