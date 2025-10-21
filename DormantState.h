#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantLifeCycleState.h"

class DormantState : public PlantLifeCycleState {
public:
    DormantState();

    ~DormantState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    bool isDead() override;

	bool isGrowingAgain(Plant* plant);
};

#endif