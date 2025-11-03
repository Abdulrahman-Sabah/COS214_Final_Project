#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

/**
 * @file SeedlingState.h
 * @brief Plant is newly sprouted.
 */

#include "PlantLifeCycleState.h"

/**
 * @class SeedlingState
 * @brief Lifecycle state for seedling plants.
 */
class SeedlingState : public PlantLifeCycleState {
public:
    SeedlingState();
    ~SeedlingState() override;

    /**
     * @brief Move to next lifecycle state
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /// @return "Seedling"
    std::string name() override;

    /// @return false (seedling is alive)
    bool isDead() override;

    /// @return true if needs care
    bool needsAttention() override;
};

#endif // SEEDLINGSTATE_H
