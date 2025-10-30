#ifndef INVENTORYSERIALIZER_H
#define INVENTORYSERIALIZER_H

#include "Inventory.h"
#include <string>

class InventorySerializer {
public:
  static void
  saveToFile(Inventory &inventory,
             const std::string &filename = "gui/inventory_state.json");
  static void
  loadFromFile(Inventory &inventory,
               const std::string &filename = "gui/inventory_state.json");

private:
  // 🆕 ADD PRIVATE HELPER METHOD
  static std::string extractJSONField(const std::string &content,
                                      const std::string &field, size_t &pos);
  static void initializeInventory(Inventory &inventory);
};

#endif