/**
 * @file SeedlingState.h
 * @brief Header file for the SeedlingState class
 */

#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class SeedlingState
 * @brief Represents the seedling state in a plant's lifecycle
 * 
 * This class implements the State pattern for plant lifecycle management.
 * In the seedling state, plants are young and require specific care before
 * advancing to the growing state.
 */
class SeedlingState : public PlantLifeCycleState {

public:
    /**
     * @brief Constructor for SeedlingState
     */
	SeedlingState();

    /**
     * @brief Destructor for SeedlingState
     */
    ~SeedlingState() override;

    /**
     * @brief Advance the plant to the next lifecycle state
     * @param plant Pointer to the plant whose state should advance
     */
	void advance(Plant* plant) override;

    /**
     * @brief Get the name of this state
     * @return String name of the seedling state
     */
	std::string name() override;

    bool isDead() override;

	bool needsAttention() override;
};

#endif