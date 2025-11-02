#ifndef INVENTORYAGGREGATE_H
#define INVENTORYAGGREGATE_H

/**
 * @file InventoryAggregate.h
 * @brief Base class providing plant collection behavior.
 */

#include <vector>
#include "Plant.h"
#include "PlantIterator.h"

class InventoryAggregate {
protected:
  std::vector<Plant *> plants;

public:
  InventoryAggregate();
  virtual ~InventoryAggregate();

  /**
   * @brief Add a plant
   * @param p Plant pointer
   */
  virtual void addPlant(Plant *p) = 0;

  /**
   * @brief Remove plant by pointer
   * @param p Plant pointer
   * @return true if removed
   */
  virtual bool removePlant(Plant *p) = 0;

  /**
   * @brief Remove plant by name
   * @param name Plant name
   * @return Pointer to removed plant or nullptr
   */
  virtual Plant *removePlantByName(const std::string &name) = 0;

  /**
   * @brief Number of plants
   * @return Size of list
   */
  size_t getSize() const;

  /**
   * @brief Create an iterator
   * @return PlantIterator pointer
   */
  virtual PlantIterator *createIterator() = 0;

  /**
   * @brief Get internal list
   * @return Vector reference
   */
  std::vector<Plant *> &getPlants();

  /**
   * @brief Print all plants
   */
  virtual void displayAll() = 0;
};

#endif
