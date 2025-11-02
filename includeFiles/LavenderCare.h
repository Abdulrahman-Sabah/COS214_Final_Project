#ifndef LAVENDERCARE_H
#define LAVENDERCARE_H

/**
 * @file LavenderCare.h
 * @brief CareStrategy implementation for Lavender plants.
 */

#include "CareStrategy.h"

class LavenderCare : public CareStrategy {
public:
  /** @brief Apply lavender-specific care actions to the given plant */
  void applyCare(Plant *plant) override;
  ~LavenderCare() override = default;
};

#endif