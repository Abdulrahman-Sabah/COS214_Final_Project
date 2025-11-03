#ifndef WEBAPI_H
#define WEBAPI_H

/**
 * @file WebAPI.h
 * @brief Thin adapter/bridge exposing Inventory operations to external callers.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>

#include "Inventory.h"
#include "InventorySerializer.h"

/**
 * @class WebAPI
 * @brief Adapter exposing Inventory operations for web server use.
 * @details Provides methods to get plant data in JSON format and modify inventory.
 */
class WebAPI {
private:
  /** @brief < Pointer to the real Inventory used by server */
  Inventory *inventory; 

public:
  /** @brief Initialize the WebAPI with an existing Inventory instance */
  void initializeInventory(Inventory &inventory);
  /** @brief Constructor */
  explicit WebAPI(Inventory *inv);

  /** @brief Get JSON representing all plants
   * @return JSON string of plant data
   */
  std::string getPlantsJSON();

  /**
   * @brief Add a new plant to the inventory
   * @param name Plant name
   * @param careType Care type string
   * @param state Initial lifecycle/state
   * @param season Season string
   * @param price Price value
   * @return true on success, false on failure
   */
  bool addPlantToInventory(const std::string &name, const std::string &careType,
                           const std::string &state, const std::string &season,
                           double price);

  /** @brief Remove plant by name from the inventory 
   * @param name Plant name
   * @return true if removed, false if not found
  */
  bool removePlantFromInventory(const std::string &name);

  /** @brief Convenience: start an embedded web server
   * @param inventory Inventory instance to use
  */
  void startWebServer(Inventory *inventory);
};

#endif // WEBAPI_H