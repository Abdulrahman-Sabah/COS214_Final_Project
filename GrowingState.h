/**
 * @file GrowingState.h
 * @brief Growing state implementation for plant lifecycle State pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class GrowingState
 * @brief Represents the active growing state in a plant's lifecycle
 * 
 * GrowingState is a concrete state in the State pattern representing
 * a plant that is actively growing. From this state, plants can either
 * advance to dormancy or die if conditions are unfavorable.
 */
class GrowingState : public PlantLifeCycleState {

public:
    /**
     * @brief Constructor for GrowingState
     */
	GrowingState();

    /**
     * @brief Destructor for GrowingState
     */
    ~GrowingState() override;

    /**
     * @brief Advances the plant to the next lifecycle state
     * @param plant Pointer to the plant whose state is being advanced
     * 
     * Can transition to DormantState under normal conditions or
     * DeadState if the plant dies during growth
     */
	void advance(Plant* plant) override;

    /**
     * @brief Gets the name of this state
     * @return String "Growing" representing this state
     */
	std::string name() override;

    /**
     * @brief Checks if the plant is dead
     * @return Boolean indicating if the plant has died
     */
    bool isDead() override;

    /**
     * @brief Checks if the plant needs attention
     * @return Boolean indicating if care is needed
     */
	bool needsAttention() override;
};

#endif