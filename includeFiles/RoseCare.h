#ifndef ROSECARE_H
#define ROSECARE_H

/**
 * @file RoseCare.h
 * @brief CareStrategy implementation for Rose plants.
 */

#include "CareStrategy.h"

class RoseCare : public CareStrategy {
public:
  /** @brief Apply rose-specific care actions to the given plant */
  void applyCare(Plant *plant) override;
  ~RoseCare() override = default;
};

#endif
