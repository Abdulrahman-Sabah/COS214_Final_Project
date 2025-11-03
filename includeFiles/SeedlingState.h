#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

/**
 * @file SeedlingState.h
 * @brief Plant is newly sprouted.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantLifeCycleState.h"

/**
 * @class SeedlingState
 * @brief Lifecycle state for seedling plants.
 * @details Inherits from PlantLifeCycleState, and represents the seedling state of a plant lifecycle
 */
class SeedlingState : public PlantLifeCycleState {
public:
    /** @brief Constructor */
    SeedlingState();
    /** @brief Destructor */
    ~SeedlingState() override;

    /**
     * @brief Move to next lifecycle state
     * @param plant Target plant
     * @details if isDead() is true, moves to DeadState; else move to the GrowingState
     */
    void advance(Plant* plant) override;

    /**
     * @brief Get the name of the state
     * @return "Seedling"
     */
    std::string name() override;

    /**
     * @brief Check if the plant is dead
     * @return true if dead, false otherwise
     */
    bool isDead() override;

    /**
     * @brief Check if the plant needs attention
     * @return true if needs attention, false otherwise
     */
    bool needsAttention() override;
};

#endif // SEEDLINGSTATE_H
