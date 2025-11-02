#ifndef DEADSTATE_H
#define DEADSTATE_H

/**
 * @file DeadState.h
 * @brief Plant lifecycle state representing a dead plant.
 *
 * DeadState implements PlantLifeCycleState for plants that have died and
 * require no further growth. It provides behaviour queries such as
 * isDead() and needsAttention().
 */

#include "PlantLifeCycleState.h"

class DeadState : public PlantLifeCycleState {
public:
  DeadState();

  ~DeadState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool needsAttention() override;
};

#endif