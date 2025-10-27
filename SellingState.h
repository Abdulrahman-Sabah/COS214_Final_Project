#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

#include "PlantLifeCycleState.h"

class SellingState : public PlantLifeCycleState {
public:
    SellingState();

    ~SellingState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    bool isDead() override;

    bool needsAttention() override;

    bool canSell();
};

#endif
