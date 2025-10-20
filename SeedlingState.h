#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantLifeCycleState.h"

class SeedlingState : public PlantLifeCycleState {

public:
	SeedlingState();

    ~SeedlingState() override;

	void advance(Plant* plant) override;

	std::string name() override;

    bool isDead() override;
};

#endif
