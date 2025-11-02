#ifndef MATURESTATE_H
#define MATURESTATE_H

/**
 * @file MatureState.h
 * @brief Plant is fully grown.
 */

#include "PlantLifeCycleState.h"

/**
 * @class MatureState
 * @brief Lifecycle state for a mature plant.
 */
class MatureState : public PlantLifeCycleState {
public:
    MatureState();
    ~MatureState() override;

    /**
     * @brief Move to next state
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /// @return "Mature"
    std::string name() override;

    /// @return false (not dead)
    bool isDead() override;

    /**
     * @brief Check if growth may resume
     * @param plant Target plant
     * @return true if plant may grow again
     */
    bool isGrowingAgain(Plant* plant);

    /// @return true if needs care
    bool needsAttention() override;
};

#endif // MATURESTATE_H
