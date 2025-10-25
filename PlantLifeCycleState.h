#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

#include <string>
#include <iostream>
#include <vector>

#include "Plant.h"

class PlantLifeCycleState {
protected:
	bool dead;
	bool attention;
public:
    PlantLifeCycleState() = default;

    virtual ~PlantLifeCycleState() {}

	virtual void advance(Plant* plant) = 0;

	virtual std::string name() = 0;

	bool getDead();

	bool getAttention();

	bool setDead(bool d);

	bool setAttention(bool a);

	virtual bool isDead() = 0;

	virtual bool needsAttention() = 0;
};

#endif 