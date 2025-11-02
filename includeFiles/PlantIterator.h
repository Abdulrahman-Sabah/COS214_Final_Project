#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

/**
 * @file PlantIterator.h
 * @brief Abstract iterator interface for Plant collections.
 */

#include "Plant.h"

class PlantIterator {
public:
  virtual ~PlantIterator() {}

  /** @brief Position iterator at the first element */
  virtual void first() = 0;

  /** @brief Advance to the next element */
  virtual void next() = 0;

  /** @brief Query whether iteration is finished */
  virtual bool isDone() = 0;

  /** @brief Retrieve current plant pointer (or nullptr if done) */
  virtual Plant *current() = 0;
};

#endif
