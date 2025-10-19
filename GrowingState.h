#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantLifeCycleState.h"

class GrowingState : public PlantLifeCycleState {
public:
	GrowingState();

    ~GrowingState() override;

	void advance(Plant* plant) override;

	std::string name() override;

    bool canSell() override;

	void enter(Plant* plant);

	void exit(Plant* plant);

	bool needsAttention(Plant* plant);

	bool isGrowingAgain(Plant* plant);
};

#endif
