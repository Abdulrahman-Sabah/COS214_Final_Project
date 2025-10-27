#include "SeedlingState.h"
#include "DeadState.h"
#include "GrowingState.h"

SeedlingState::SeedlingState() : PlantLifeCycleState() {}

SeedlingState::~SeedlingState() = default;

void SeedlingState::advance(Plant* plant) {
    if(isDead()) {
        plant->setLifeCycle(new DeadState());
        std::cout << plant->getName() << " has died in the " << plant->getLifeCycle()->name() << " state." << std::endl;
    } else {
        plant->setLifeCycle(new GrowingState());
        std::cout << plant->getName() << " has advanced to the " << plant->getLifeCycle()->name() << " state." << std::endl;
    }
}

std::string SeedlingState::name() { return "Seedling"; }

bool SeedlingState::isDead() { 
    if(dead) return true;
    return false;
}

bool SeedlingState::needsAttention() {
    if(attention) return true;
    return false;
}
