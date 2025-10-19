#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

#include <string>
#include <iostream>
#include <vector>

#include "Plant.h"

class PlantLifeCycleState {
public:
    PlantLifeCycleState() = default;

    virtual ~PlantLifeCycleState() {}

	virtual void advance(Plant* plant) = 0;

	virtual std::string name() = 0;

	virtual bool canSell() = 0;
};

#endif 