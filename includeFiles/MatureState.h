#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantLifeCycleState.h"

class MatureState : public PlantLifeCycleState {
public:
  MatureState();

  ~MatureState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool isGrowingAgain(Plant *plant);

  bool needsAttention() override;
};

#endif