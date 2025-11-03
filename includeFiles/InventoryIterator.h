#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

/**
 * @file InventoryIterator.h
 * @brief It defines the InventoryIterator class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include "PlantIterator.h"
#include <vector>

/**
 * @class InventoryIterator
 * @brief Concrete iterator for plant collections.
 */
class InventoryIterator : public PlantIterator {
private:
  /** @brief Pointer to the vector of plants */
  std::vector<Plant *> &plants;
  /** @brief Current index in the vector */
  size_t currentIndex;

public:
  /**
   * @brief Constructor
   * @param plantList Pointer to plant list
   */
  InventoryIterator(std::vector<Plant *> &plantList);

  /**
   * @brief Destructor
   */
  ~InventoryIterator();

  /**
   * @brief Position iterator at the first element
   */
  void first() override;

  /**
   * @brief Advance to the next element
   */
  void next() override;

  /**
   * @brief Check whether we reached the end
   * @return true if at the end, false otherwise
   */
  bool isDone() override;

  /**
   * @brief Retrieve current plant pointer
   * @return Pointer to current plant, or nullptr if done
   */
  Plant *current() override;
};

#endif
