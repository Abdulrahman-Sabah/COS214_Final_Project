#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

/**
 * @file PlantIterator.h
 * @brief Abstract iterator interface for Plant collections.
 * @author Git it done group members
 * @date 10-2025
 */

#include "Plant.h"

/** @class PlantIterator
 *  @brief Abstract iterator for Plant collections.
 */
class PlantIterator {
public:
  virtual ~PlantIterator() {}

  /** @brief Position iterator at the first element */
  virtual void first() = 0;

  /** @brief Advance to the next element */
  virtual void next() = 0;

  /** @brief Query whether iteration is finished
   * @return true if done, false otherwise
   */
  virtual bool isDone() = 0;

  /** @brief Retrieve current plant pointer
   * @return Current Plant pointer or nullptr if done
   */
  virtual Plant *current() = 0;
};

#endif
