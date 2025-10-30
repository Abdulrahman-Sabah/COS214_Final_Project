#ifndef WEBAPI_H
#define WEBAPI_H

#include "Inventory.h"
#include "InventorySerializer.h"
#include <string>

class WebAPI {
private:
  Inventory *inventory; // The REAL C++ inventory

public:
  // ADD THIS DECLARATION:
  void initializeInventory(Inventory &inventory);

  WebAPI(Inventory *inv);

  // Get plants from the REAL C++ inventory
  std::string getPlantsJSON();

  // Add plant to the REAL C++ inventory
  bool addPlantToInventory(const std::string &name, const std::string &careType,
                           const std::string &state, const std::string &season,
                           double price);

  // Remove plant from REAL C++ inventory
  bool removePlantFromInventory(const std::string &name);

  void startWebServer(Inventory *inventory);
};

#endif // WEBAPI_H