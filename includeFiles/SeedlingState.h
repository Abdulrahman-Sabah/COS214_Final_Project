#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

/**
 * @file SeedlingState.h
 * @brief Plant lifecycle state representing newly germinated seedlings.
 */

#include "PlantLifeCycleState.h"

class SeedlingState : public PlantLifeCycleState {
public:
  SeedlingState();

  ~SeedlingState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool needsAttention() override;
};

#endif