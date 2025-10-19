#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantLifeCycleState.h"

class MatureState : public PlantLifeCycleState {
public:
    MatureState();

    ~MatureState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    bool canSell() override;

    void enter(Plant* plant);

    void exit(Plant* plant);

    bool needsAttention(Plant* plant);

    bool isGrowingAgain(Plant* plant);
};

#endif
