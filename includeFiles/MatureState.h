#ifndef MATURESTATE_H
#define MATURESTATE_H
/**
 * @file MatureState.h
 * @brief It defines the MatureState class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantLifeCycleState.h"

/**
 * @class MatureState
 * @brief Lifecycle state for a mature plant.
 * @details Inherits from PlantLifeCycleState.
 */
class MatureState : public PlantLifeCycleState {
public:
  /**
   * @brief Constructor
   */
  MatureState();
  /**
   * @brief Destructor
   */
  ~MatureState() override;

  /**
   * @brief Move to next state
   * @param plant Target plant
   * @details if isDead() then plant moves to DeadState else moves to
   * sellingState
   */
  void advance(Plant *plant) override;

  /**
   * @brief Get the state name
   * @return "Mature"
   */
  std::string name() override;

  /**
   * @brief Check if the plant is dead
   * @return returns true if dead, false otherwise
   */
  bool isDead() override;

  /**
   * @brief Check if growth may resume
   * @param plant Target plant
   * @return true if plant may grow again, false otherwise
   */
  bool isGrowingAgain(Plant *plant);

  /**
   * @brief Check if the plant needs attention
   * @return returns true if needs attention, false otherwise
   */
  bool needsAttention() override;
};

#endif // MATURESTATE_H
