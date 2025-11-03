/**
 * @file GrowingState.h
 * @brief It defines the GrowingState class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class GrowingState
 * @brief Lifecycle state for a growing plant.
 * @details Inherits from PlantLifeCycleState and represents the growing state
 * of a plant's lifecycle.
 */
class GrowingState : public PlantLifeCycleState {
public:
  /**
   * @brief Default Constructor
   */
  GrowingState();
  /**
   * @brief Default Destructor
   */
  ~GrowingState() override;

  /**
   * @brief Move to next lifecycle state
   * @param plant Target plant
   * @details if the plant is dead, moves to deadState else moves to
   * DormantState
   */
  void advance(Plant *plant) override;

  /**
   * @brief Get state name
   * @return "Growing"
   */
  std::string name() override;

  /**
   * @brief Check if plant is dead
   * @return true if dead, false otherwise
   */
  bool isDead() override;

  /**
   * @brief Check if plant requires attention
   * @return true if requires attention, false otherwise
   */
  bool needsAttention() override;
};

#endif // GROWINGSTATE_H
