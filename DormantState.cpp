/**
 * @file DormantState.cpp
 * @brief Implementation of the DormantState class
 * @author COS214 Students
 * @date 2024
 */

#include "DormantState.h"
#include "DeadState.h"
#include "GrowingState.h"
#include "MatureState.h"

DormantState::DormantState() : PlantLifeCycleState(), growing(false) {}

DormantState::~DormantState() = default;

void DormantState::advance(Plant* plant) {
    if(isDead()) {
         plant->setLifeCycle(new DeadState());
         std::cout << plant->getName() << " has died in the " << plant->getLifeCycle()->name() << " state." << std::endl;
    } else if(isGrowingAgain()) {
        plant->setLifeCycle(new GrowingState());
        std::cout << plant->getName() << " has advanced to the " << plant->getLifeCycle()->name() << " state." << std::endl;
    } else {
        plant->setLifeCycle(new MatureState());
        std::cout << plant->getName() << " has advanced to the " << plant->getLifeCycle()->name() << " state." << std::endl;
    }
}

std::string DormantState::name() { return "Dormant"; }

bool DormantState::isDead() { 
    if(dead) return true;
    return false;
 }

bool DormantState::getGrowing() { return growing; }

void DormantState::setGrowing(bool grow) { growing = grow; }

bool DormantState::isGrowingAgain() {
    if(growing) return true;
    return false;
}

bool DormantState::needsAttention() {
    if(attention) return true;
    return false;
}
