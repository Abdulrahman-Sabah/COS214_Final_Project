
#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

/**
 * @file DormantState.h
 * @brief It defines the DormantState class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantLifeCycleState.h"

/**
 * @class DormantState
 * @brief Plant is dormant
 * @details Inherits from PlantLifeCycleState and represents the Dormant
 * lifecycle state of a plant. It checks if plant is growing again or should
 * advance to MatureState.
 */
class DormantState : public PlantLifeCycleState {
private:
  /** @brief boolean flag to determine if plant is growing or not
   */
  bool growing;

public:
  /**
   * @brief Default constructor
   */
  DormantState();
  /**
   * @brief Default destructor
   */
  ~DormantState() override;

  /**
   * @brief Move to next lifecycle state
   * @param plant Target plant
   */
  void advance(Plant *plant) override;

  /**
   * @brief Get the name of the state
   * @return "Dormant"
   */
  std::string name() override;

  /**
   * @brief Check if plant is dead
   * @return true if dead
   */
  bool isDead() override;

  /**
   * @brief Get possible growth return
   * @return growing boolean variable
   */
  bool getGrowing();

  /**
   * @brief Set possible growth return
   * @param grow True if plant may grow again
   */
  void setGrowing(bool grow);

  /**
   * @brief Check if plant is growing again
   * @return true if plant is growing again, false otherwise
   */
  bool isGrowingAgain();

  /**
   *
   * @brief Check if plant needs attention
   * @return true if needs attention, false otherwise
   */
  bool needsAttention() override;
};

#endif // DORMANTSTATE_H
