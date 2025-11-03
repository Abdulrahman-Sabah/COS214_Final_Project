#ifndef INVENTORYSERIALIZER_H
#define INVENTORYSERIALIZER_H

/**
 * @file InventorySerializer.h
 * @brief It defines the InventorySerializer class with its functions.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>

#include "Inventory.h"

/**
 * @class InventorySerializer
 * @brief Handles saving and loading Inventory state to and from a file.
 */
class InventorySerializer {
public:
  /**
   * @brief Save inventory state to a file in JSON format
   * @param inventory Reference to Inventory object
   * @param filename Name of the file to save to
   */
  static void
  saveToFile(Inventory &inventory,
             const std::string &filename = "gui/inventory_state.json");
  /**
   * @brief Load inventory state from a file in JSON format
   * @param inventory Reference to Inventory object
   * @param filename Name of the file to load from
   */
  static void
  loadFromFile(Inventory &inventory,
               const std::string &filename = "gui/inventory_state.json");

private:
  /**
   * @brief Extract a field value from JSON content
   * @param content JSON content as string
   * @param field Field name to extract
   * @param pos Current position in content (updated after extraction)
   * @return Extracted value
   */
  // ADD PRIVATE HELPER METHOD
  static std::string extractJSONField(const std::string &content,
                                      const std::string &field, size_t &pos);
  /**
   * @brief Initialize inventory with default plants
   * @param inventory Reference to Inventory object
   */
  static void initializeInventory(Inventory &inventory);
};

#endif