/**
 * @file SellingState.h
 * @brief Selling state implementation for the State pattern
 * @author COS214 Students
 * @date 2024
 */

#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class SellingState
 * @brief Represents the selling state in a plant's lifecycle
 * 
 * This state represents when a plant is ready for sale. It's the final
 * state in the plant lifecycle where the plant is mature enough to be
 * sold to customers.
 */
class SellingState : public PlantLifeCycleState {
public:
    /**
     * @brief Default constructor
     */
    SellingState();

    /**
     * @brief Virtual destructor
     */
    ~SellingState() override;

    /**
     * @brief Advances the plant state (typically no further advancement from selling)
     * @param plant The plant to advance
     */
    void advance(Plant* plant) override;

    /**
     * @brief Gets the name of this state
     * @return "Selling" as the state name
     */
    std::string name() override;

    /**
     * @brief Checks if the plant is dead in this state
     * @return True if the plant has died
     */
    bool isDead() override;

    /**
     * @brief Checks if the plant needs attention in this state
     * @return True if the plant needs care
     */
    bool needsAttention() override;

    /**
     * @brief Checks if the plant can be sold
     * @return True if the plant is ready for sale
     */
    bool canSell();
};

#endif