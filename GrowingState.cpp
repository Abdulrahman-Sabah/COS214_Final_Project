#include "GrowingState.h"
#include "DeadState.h"
#include "DormantState.h"

GrowingState::GrowingState() : PlantLifeCycleState() {}

GrowingState::~GrowingState() = default;

void GrowingState::advance(Plant* plant) {
    if(isDead()) {
        plant->setLifeCycle(new DeadState());
        std::cout << plant->getName() << " has died in the " << plant->getLifeCycle()->name() << " state." << std::endl;
    } else {
        plant->setLifeCycle(new DormantState());
        std::cout << plant->getName() << " has advanced to the " << plant->getLifeCycle()->name() << " state." << std::endl;
    }
}

std::string GrowingState::name() { return "Growing"; }

bool GrowingState::isDead() { 
    if(dead) return true;
    return false;
 }

bool GrowingState::needsAttention() {
    if(attention) return true;
    return false;
}