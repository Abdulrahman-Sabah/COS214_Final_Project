#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantLifeCycleState.h"

class GrowingState : public PlantLifeCycleState {

public:
	GrowingState();

    ~GrowingState() override;

	void advance(Plant* plant) override;

	std::string name() override;

    bool isDead() override;

	bool needsAttention() override;
};

#endif