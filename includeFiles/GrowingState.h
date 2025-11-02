#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

/**
 * @file GrowingState.h
 * @brief Plant lifecycle state for actively growing plants.
 *
 * GrowingState represents a phase where plants progress towards maturity.
 */

#include "PlantLifeCycleState.h"

class GrowingState : public PlantLifeCycleState {
public:
  GrowingState();

  ~GrowingState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool needsAttention() override;
};

#endif