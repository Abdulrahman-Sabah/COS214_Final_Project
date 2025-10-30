/**
 * @file DeadState.cpp
 * @brief Implementation of DeadState for plant lifecycle management
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "DeadState.h"

DeadState::DeadState() {
    dead = true;
    attention = false;
}

DeadState::~DeadState() = default;

void DeadState::advance(Plant* plant) {
    std::cout << plant->getName() << " is dead." << std::endl;
}

std::string DeadState::name() { return "Dead"; }

bool DeadState::isDead() { return true; }

bool DeadState::needsAttention() { return false; }

