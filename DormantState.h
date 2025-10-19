#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantLifeCycleState.h"

class DormantState : public PlantLifeCycleState {
public:
    DormantState();

    ~DormantState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    bool canSell() override;

    void enter(Plant* plant);

	void exit(Plant* plant);

	bool needsAttention(Plant* plant);

	bool isGrowingAgain(Plant* plant);
};

#endif