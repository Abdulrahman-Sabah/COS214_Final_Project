#ifndef MATURESTATE_H
#define MATURESTATE_H

/**
 * @file MatureState.h
 * @brief Plant lifecycle state representing maturity.
 */

#include "PlantLifeCycleState.h"

class MatureState : public PlantLifeCycleState {
public:
  MatureState();

  ~MatureState() override;

  /** @brief Advance the plant's lifecycle from mature */
  void advance(Plant *plant) override;

  /** @brief Name of this lifecycle state */
  std::string name() override;

  bool isDead() override;

  /** @brief Query if plant will re-enter a growing phase */
  bool isGrowingAgain(Plant *plant);

  bool needsAttention() override;
};

#endif