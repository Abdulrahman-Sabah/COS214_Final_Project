#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantLifeCycleState.h"

class DeadState : public PlantLifeCycleState {
public:
    DeadState();

    ~DeadState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    void enter(Plant* plant);

	void exit(Plant* plant);

	bool needsAttention(Plant* plant);

    bool isDead(Plant* plant);
};

#endif