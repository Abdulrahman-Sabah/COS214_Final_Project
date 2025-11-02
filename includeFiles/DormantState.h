#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

/**
 * @file DormantState.h
 * @brief Plant lifecycle state for dormant (non-growing) plants.
 *
 * DormantState implements behaviour for plants that are not actively
 * growing. It can track whether a plant may resume growth later and
 * whether attention is required.
 */

#include "PlantLifeCycleState.h"

class DormantState : public PlantLifeCycleState {
private:
  bool growing;

public:
  DormantState();

  ~DormantState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool getGrowing();

  void setGrowing(bool grow);

  bool isGrowingAgain();

  bool needsAttention() override;
};

#endif