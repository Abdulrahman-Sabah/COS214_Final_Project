/**
 * @file MatureState.cpp
 * @brief Implementation of the MatureState class
 * @author COS214 Students
 * @date 2024
 */

#include "MatureState.h"
#include "DeadState.h"
#include "SellingState.h"

MatureState::MatureState() = default;

MatureState::~MatureState() = default;

void MatureState::advance(Plant* plant) {
    if(isDead()) {
        plant->setLifeCycle(new DeadState());
        std::cout << plant->getName() << " has died in the " << plant->getLifeCycle()->name() << " state." << std::endl;
    } else {
        plant->setLifeCycle(new SellingState());
        std::cout << plant->getName() << " has advanced to the " << plant->getLifeCycle()->name() << " state." << std::endl;
    }
}


std::string MatureState::name() { return "Mature"; }

bool MatureState::isDead() { 
    if(dead) return true;
    return false;
}

bool MatureState::needsAttention() {
    if(attention) return true;
    return false;
}