#include "GrowingState.h"
#include "DeadState.h"
#include "MatureState.h"

GrowingState::GrowingState() = default;

GrowingState::~GrowingState() = default;

void GrowingState::advance(Plant* plant) {
    if(isDead()) plant->setState(new DeadState());
    else if(isGrowingAgain(plant)) plant->setState(new MatureState());
}

std::string GrowingState::name() { return "Growing"; }

bool GrowingState::isDead() { return false; }
