/**
 * @file DormantState.h
 * @brief Dormant state implementation for the State pattern
 * @author COS214 Students
 * @date 2024
 */

#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class DormantState
 * @brief Represents the dormant state in a plant's lifecycle
 *
 * This state represents when a plant is in a dormant phase, typically during
 * unfavorable growing conditions. The plant conserves energy and waits for
 * better conditions to resume growth.
 */
class DormantState : public PlantLifeCycleState {
private:
  bool growing; ///< Indicates if the plant is starting to grow again
public:
  /**
   * @brief Default constructor
   */
  DormantState();

  /**
   * @brief Virtual destructor
   */
  ~DormantState() override;

  /**
   * @brief Advances the plant to the next lifecycle state if conditions are met
   * @param plant The plant to advance
   */
  void advance(Plant *plant) override;

  /**
   * @brief Gets the name of this state
   * @return "Dormant" as the state name
   */
  std::string name() override;

  /**
   * @brief Checks if the plant is dead in this state
   * @return False, as dormant plants are still alive
   */
  bool isDead() override;

  /**
   * @brief Gets the growing status
   * @return True if the plant is starting to grow again
   */
  bool getGrowing();

  /**
   * @brief Sets the growing status
   * @param grow The new growing status
   */
  void setGrowing(bool grow);

  /**
   * @brief Checks if the plant is growing again
   * @return True if the plant is starting to grow
   */
  bool isGrowingAgain();

  /**
   * @brief Checks if the plant needs attention in this state
   * @return True if the plant needs care
   */
  bool needsAttention() override;
};

#endif