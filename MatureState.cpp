#include "MatureState.h"
#include "DeadState.h"
#include "SellingState.h"

MatureState::MatureState() = default;

MatureState::~MatureState() = default;

void MatureState::advance(Plant* plant) {
    // if(isDead()) plant->setState(new DeadState());
    // else plant->setState(new SellingState());
}

std::string MatureState::name() { return "Mature"; }

bool MatureState::isDead() { return false; }
