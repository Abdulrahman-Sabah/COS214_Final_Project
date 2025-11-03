
#ifndef CACTUSCARE_H
#define CACTUSCARE_H

/**
 * @file CactusCare.h
 * @brief It defines the CactusCare class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "CareStrategy.h"

/**
 * @class CactusCare
 * @brief Concrete strategy providing cactus-appropriate plant care.
 * @details Inherits from CareStrategy and implements care strategies relating
 * to cacti.
 */
class CactusCare : public CareStrategy {
public:
  /**
   * @brief Apply cactus-specific care to the given plant
   * @param plant Pointer to the plant receiving care.
   */
  void applyCare(Plant *plant) override;

  /**
   * @brief Virtual default destructor for safe cleanup.
   */
  ~CactusCare() override = default;
};

#endif // CACTUSCARE_H
