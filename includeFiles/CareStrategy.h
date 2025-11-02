#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

/**
 * @file CareStrategy.h
 * @brief Abstract strategy interface for plant care behaviors.
 *
 * Declares CareStrategy: the Strategy pattern interface that encapsulates
 * plant-specific care routines (watering, pruning, etc.).
 */

#include <iostream>
class Plant;

class CareStrategy {
public:
  virtual void applyCare(Plant *plant) = 0;
  virtual ~CareStrategy() = default;
};

#endif