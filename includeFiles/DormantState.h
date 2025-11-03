/**
 * @file DormantState.h
 * @brief Lifecycle state for a dormant plant.
 */

#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class DormantState
 * @brief Plant is paused in growth.
 */
class DormantState : public PlantLifeCycleState {
private:
    bool growing;

public:
    DormantState();
    ~DormantState() override;

    /**
     * @brief Move to next lifecycle state
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /// @return "Dormant"
    std::string name() override;

    /// @return false (not dead)
    bool isDead() override;

    /// @return true if growth expected later
    bool getGrowing();

    /**
     * @brief Set possible growth return
     * @param grow True if plant may grow again
     */
    void setGrowing(bool grow);

    /// @return true if plant is resuming growth
    bool isGrowingAgain();

    /// @return true if needs care
    bool needsAttention() override;
};

#endif // DORMANTSTATE_H
