#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

/**
 * @file SellingState.h
 * @brief Lifecycle state for plants ready to be sold.
 */

#include "PlantLifeCycleState.h"

/**
 * @class SellingState
 * @brief Plant available for sale.
 */
class SellingState : public PlantLifeCycleState {
public:
    SellingState();
    ~SellingState() override;

    /**
     * @brief Move to next lifecycle state
     * @param plant Target plant
     */
    void advance(Plant* plant) override;

    /// @return "Selling"
    std::string name() override;

    /// @return false (not dead)
    bool isDead() override;

    /// @return true if needs care
    bool needsAttention() override;

    /**
     * @brief Check if plant can be sold
     * @return true if sellable
     */
    bool canSell();
};

#endif // SELLINGSTATE_H
