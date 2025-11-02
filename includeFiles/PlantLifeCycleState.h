/**
 * @file PlantLifeCycleState.h
 * @brief Abstract base class for plant lifecycle states
 * @author COS214 Students
 * @date 2024
 */

#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

#include <iostream>
#include <string>
#include <vector>

#include "Plant.h"

/**
 * @class PlantLifeCycleState
 * @brief Abstract base class implementing the State pattern for plant lifecycle
 * management
 *
 * This class defines the interface for all plant lifecycle states and provides
 * common functionality for state management. Each concrete state represents
 * a different phase in a plant's lifecycle (Seedling, Growing, Mature, etc.).
 */
class PlantLifeCycleState {
protected:
  bool dead;      ///< Indicates if the plant is dead
  bool attention; ///< Indicates if the plant needs attention
public:
  /**
   * @brief Default constructor
   */
  PlantLifeCycleState() = default;

  /**
   * @brief Virtual destructor for proper cleanup
   */
  virtual ~PlantLifeCycleState() = default;

  /**
   * @brief Pure virtual method to advance plant to next lifecycle state
   * @param plant The plant to advance to next state
   */
  virtual void advance(Plant *plant) = 0;

  /**
   * @brief Pure virtual method to get the name of this state
   * @return String name of the current state
   */
  virtual std::string name() = 0;

  /**
   * @brief Gets the dead status
   * @return True if plant is dead, false otherwise
   */
  bool getDead();

  /**
   * @brief Gets the attention status
   * @return True if plant needs attention, false otherwise
   */
  bool getAttention();

  /**
   * @brief Sets the dead status
   * @param d The new dead status
   * @return The updated dead status
   */
  bool setDead(bool d);

  /**
   * @brief Sets the attention status
   * @param a The new attention status
   * @return The updated attention status
   */
  bool setAttention(bool a);

  /**
   * @brief Pure virtual method to check if plant is dead
   * @return True if plant is dead, false otherwise
   */
  virtual bool isDead() = 0;

  /**
   * @brief Pure virtual method to check if plant needs attention
   * @return True if plant needs attention, false otherwise
   */
  virtual bool needsAttention() = 0;
};

#endif