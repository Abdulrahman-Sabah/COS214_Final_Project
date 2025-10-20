#include "SeedlingState.h"
#include "DeadState.h"
#include "GrowingState.h"

SeedlingState::SeedlingState() = default;

SeedlingState::~SeedlingState() = default;

void SeedlingState::advance(Plant* plant) {
    if(isDead()) plant->setState(new DeadState());
    else plant->setState(new GrowingState());
}

std::string SeedlingState::name() { return "Seedling"; }

bool SeedlingState::isDead() { return false; }
