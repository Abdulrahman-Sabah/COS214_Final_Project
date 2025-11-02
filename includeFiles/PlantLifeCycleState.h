#ifndef PLANTLIFECYCLESTATE_H
#define PLANTLIFECYCLESTATE_H

/**
 * @file PlantLifeCycleState.h
 * @brief Abstract state interface for plant lifecycle states.
 *
 * Represents states such as Seedling, Growing, Mature, Dormant and Dead.
 */

#include <iostream>
#include <string>
#include <vector>

#include "Plant.h"

class PlantLifeCycleState {
protected:
  bool dead;
  bool attention;

public:
  PlantLifeCycleState();

  virtual ~PlantLifeCycleState() = default;

  /** @brief Advance lifecycle to the next phase (override in subclasses) */
  virtual void advance(Plant *plant) = 0;

  /** @brief Return a human-friendly name for this lifecycle state */
  virtual std::string name() = 0;

  bool getDead();

  bool getAttention();

  bool setDead(bool d);

  bool setAttention(bool a);

  virtual bool isDead() = 0;

  virtual bool needsAttention() = 0;
};

#endif