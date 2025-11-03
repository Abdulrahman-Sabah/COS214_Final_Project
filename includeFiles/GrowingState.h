/**
 * @file GrowingState.h
 * @brief Plant is actively growing.
 */

#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class GrowingState
 * @brief Lifecycle state for a growing plant.
 */
class GrowingState : public PlantLifeCycleState {
public:
    GrowingState();
    ~GrowingState() override;

    /**
     * @brief Move to next lifecycle state
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /// @return "Growing"
    std::string name() override;

    /// @return false (not dead)
    bool isDead() override;

    /// @return true if plant requires care
    bool needsAttention() override;
};

#endif // GROWINGSTATE_H
