#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantLifeCycleState.h"

class DormantState : public PlantLifeCycleState {
private:
    bool growing;
public:
    DormantState();

    ~DormantState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    bool isDead() override;

    bool getGrowing();

    void setGrowing(bool grow);

	bool isGrowingAgain();

    bool needsAttention() override;
};

#endif