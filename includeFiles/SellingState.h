#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

/**
 * @file SellingState.h
 * @brief Plant lifecycle state representing items available for sale.
 */

#include "PlantLifeCycleState.h"

class SellingState : public PlantLifeCycleState {
public:
  SellingState();

  ~SellingState() override;

  void advance(Plant *plant) override;

  std::string name() override;

  bool isDead() override;

  bool needsAttention() override;

  /** @brief Query whether the plant can be sold in the current state */
  bool canSell();
};

#endif