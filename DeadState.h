/**
 * @file DeadState.h
 * @brief Dead state implementation for plant lifecycle State pattern
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class DeadState
 * @brief Represents the final dead state in a plant's lifecycle
 * 
 * DeadState is a concrete state in the State pattern representing
 * a plant that has died. This is typically a terminal state from
 * which no further transitions are possible.
 */
class DeadState : public PlantLifeCycleState {
public:
    /**
     * @brief Constructor for DeadState
     * 
     * Initializes the dead state with appropriate flags
     */
    DeadState();

    /**
     * @brief Destructor for DeadState
     */
    ~DeadState() override;

    /**
     * @brief Attempts to advance the plant's lifecycle state
     * @param plant Pointer to the plant whose state is being advanced
     * 
     * Since this is the dead state, no advancement is possible
     */
    void advance(Plant* plant) override;

    /**
     * @brief Gets the name of this state
     * @return String "Dead" representing this state
     */
    std::string name() override;

    /**
     * @brief Checks if the plant is dead
     * @return Always returns true for DeadState
     */
    bool isDead() override;

    /**
     * @brief Checks if the plant needs attention
     * @return Always returns false for DeadState (beyond help)
     */
    bool needsAttention() override;
};

#endif