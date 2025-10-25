#include "SellingState.h"

SellingState::SellingState() = default;

SellingState::~SellingState() = default;

void SellingState::advance(Plant* plant) {
    if (!plant) return;
    std::cout << "Plant " << plant->getName() << " is ready for sale." << std::endl;
}

std::string SellingState::name() { return "Selling"; }

bool SellingState::canSell() { 
    return true;
}

bool SellingState::isDead() { 
    if(dead) return true;
    return false;
 }