/**
 * @file MatureState.h
 * @brief Mature state implementation for the State pattern
 * @author COS214 Students
 * @date 2024
 */

#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantLifeCycleState.h"

/**
 * @class MatureState
 * @brief Represents the mature state in a plant's lifecycle
 *
 * This state represents when a plant has reached full maturity and is
 * at its peak condition. From here, the plant may enter dormancy or
 * potentially decline if not properly cared for.
 */
class MatureState : public PlantLifeCycleState {
public:
  /**
   * @brief Default constructor
   */
  MatureState();

  /**
   * @brief Virtual destructor
   */
  ~MatureState() override;

  /**
   * @brief Advances the plant to the next lifecycle state if conditions are met
   * @param plant The plant to advance
   */
  void advance(Plant *plant) override;

  /**
   * @brief Gets the name of this state
   * @return "Mature" as the state name
   */
  std::string name() override;

  /**
   * @brief Checks if the plant is dead in this state
   * @return True if the plant has died
   */
  bool isDead() override;

  /**
   * @brief Checks if the plant is growing again
   * @param plant The plant to check
   * @return True if the plant is continuing to grow
   */
  bool isGrowingAgain(Plant *plant);

  /**
   * @brief Checks if the plant needs attention in this state
   * @return True if the plant needs care
   */
  bool needsAttention() override;
};

#endif