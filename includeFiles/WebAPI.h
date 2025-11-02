#ifndef WEBAPI_H
#define WEBAPI_H

/**
 * @file WebAPI.h
 * @brief Thin adapter/bridge exposing Inventory operations to external callers.
 *
 * WebAPI provides a small façade around the internal Inventory model so web
 * handlers or other external services can access inventory state and perform
 * basic operations without coupling directly to internal data structures.
 */

#include <string>

#include "Inventory.h"
#include "InventorySerializer.h"

class WebAPI {
private:
  Inventory *inventory; /**< Pointer to the real Inventory used by server */

public:
  /** @brief Initialize the WebAPI with an existing Inventory instance */
  void initializeInventory(Inventory &inventory);

  explicit WebAPI(Inventory *inv);

  /** @brief Get JSON representing all plants (stringified HTTP body) */
  std::string getPlantsJSON();

  /**
   * @brief Add a new plant to the inventory
   * @param name Plant name
   * @param careType Care type string
   * @param state Initial lifecycle/state
   * @param season Season string
   * @param price Price value
   * @return true on success
   */
  bool addPlantToInventory(const std::string &name, const std::string &careType,
                           const std::string &state, const std::string &season,
                           double price);

  /** @brief Remove plant by name from the inventory */
  bool removePlantFromInventory(const std::string &name);

  /** @brief Convenience: start an embedded web server (optional) */
  void startWebServer(Inventory *inventory);
};

#endif // WEBAPI_H