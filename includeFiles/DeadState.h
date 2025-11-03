
#ifndef DEADSTATE_H
#define DEADSTATE_H

/**
 * @file DeadState.h
 * @brief It defines the DeadState class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantLifeCycleState.h"

/**
 * @class DeadState
 * @brief Lifecycle state for a dead plant.
 * @details Inherits from PlantLifeCycleState and represents the dead state of a plant.
 */
class DeadState : public PlantLifeCycleState {
public:
    DeadState();
    ~DeadState() override;

    /**
     * @brief No further state progression
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /**
     * @brief Get the name of the state
     * @return "Dead"
     */
    std::string name() override;

    /**
     * @brief Check if plant is dead (always dead)
     * @return true
     */
    bool isDead() override;

    /**
     * @brief Check if the plant needs attention
     * @return false
     */
    bool needsAttention() override;
};

#endif // DEADSTATE_H
