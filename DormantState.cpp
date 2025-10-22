#include "DormantState.h"
#include "DeadState.h"
#include "GrowingState.h"
#include "MatureState.h"

DormantState::DormantState() = default;

DormantState::~DormantState() = default;

void DormantState::advance(Plant* plant) 
{
    // if(isDead()) plant->setState(new DeadState());
    // else if(isGrowingAgain(plant)) plant->setState(new GrowingState());
    // else plant->setState(new MatureState());
}

std::string DormantState::name() { return "Dormant"; }

bool DormantState::isDead() { return false; }
