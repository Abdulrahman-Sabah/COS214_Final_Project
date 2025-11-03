#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

/**
 * @file SellingState.h
 * @brief Lifecycle state for plants ready to be sold.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantLifeCycleState.h"

/**
 * @class SellingState
 * @brief Plant available for sale.
 * @details Inherits from PlantLifeCycleState, represents the selling state of a
 * plant lifecycle
 */
class SellingState : public PlantLifeCycleState {
public:
  /** @brief Constructor  */
  SellingState();
  /** @brief Destructor */
  ~SellingState() override;

  /**
   * @brief End of lifecycle reached, cannot advance further
   * @param plant Target plant
   */
  void advance(Plant *plant) override;

  /**
   * @brief Get the name of the state
   * @return "Selling"
   */
  std::string name() override;

  /// @return false (not dead)
  bool isDead() override;

  /**
   * @brief Check if the plant needs attention
   * @return true if needs attention, false otherwise
   */
  bool needsAttention() override;

  /**
   * @brief Check if plant can be sold
   * @return true if sellable
   */
  bool canSell();
};

#endif // SELLINGSTATE_H
