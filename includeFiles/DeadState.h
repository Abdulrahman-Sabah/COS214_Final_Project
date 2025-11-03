/**
 * @file DeadState.h
 * @brief Plant state when the plant is dead.
 */

#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class DeadState
 * @brief Lifecycle state for a dead plant.
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

    /// @return "Dead"
    std::string name() override;

    /// @return true (always dead)
    bool isDead() override;

    /// @return false (no care needed)
    bool needsAttention() override;
};

#endif // DEADSTATE_H
