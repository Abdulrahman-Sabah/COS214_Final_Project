#ifndef INVENTORY_H
#define INVENTORY_H

/**
 * @file Inventory.h
 * @brief Collection and management of Plant objects.
 */

#include <vector>
#include "Plant.h"
#include "PlantIterator.h"

class Inventory {
private:
  std::vector<Plant *> plants;

public:
  /**
   * @brief Delete all plants and clear list
   */
  void clear() {
    for (Plant *plant : plants) {
      delete plant;
    }
    plants.clear();
  }

  Inventory();
  ~Inventory();

  /**
   * @brief Add a plant
   * @param p Plant pointer
   */
  void addPlant(Plant *p);

  /**
   * @brief Remove a plant by pointer
   * @param p Plant pointer
   * @return true if removed
   */
  bool removePlant(Plant *p);

  /**
   * @brief Remove a plant by name
   * @param name Plant name
   * @return true if removed
   */
  bool removePlantByName(const std::string &name);

  /**
   * @brief Get number of plants
   * @return Size of vector
   */
  size_t getSize() const;

  /**
   * @brief Create a new iterator
   * @return PlantIterator pointer
   */
  PlantIterator *createIterator();

  /**
   * @brief Get internal plant list
   * @return Reference to vector
   */
  std::vector<Plant *> &getPlants();

  /**
   * @brief Print all plants
   */
  void displayAll();

  /**
   * @brief Check if plant exists
   * @param p Plant pointer
   * @return true if found
   */
  bool hasPlant(Plant *p);

  /**
   * @brief Access by index
   * @param index Position
   * @return Plant pointer or nullptr
   */
  Plant *at(int index) const;
};

#endif
