#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "PlantLifeCycleState.h"

class DeadState : public PlantLifeCycleState {
 public:
  DeadState();

  ~DeadState() override;

  void advance(Plant* plant) override;

  std::string name() override;

  bool isDead() override;

  bool needsAttention() override;
};

#endif