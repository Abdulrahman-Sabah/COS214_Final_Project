#ifndef CACTUSCARE_H
#define CACTUSCARE_H

/**
 * @file CactusCare.h
 * @brief CareStrategy implementation for cactus plants.
 *
 * Implements watering and minimal care behaviour suited for cacti.
 */

#include "CareStrategy.h"

class CactusCare : public CareStrategy {
public:
  void applyCare(Plant *plant) override;
  ~CactusCare() override = default;
};

#endif