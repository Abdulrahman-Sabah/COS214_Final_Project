#ifndef INVENTORYSERIALIZER_H
#define INVENTORYSERIALIZER_H

#include "Inventory.h"
#include <string>

class InventorySerializer {
public:
    static void saveToFile(Inventory& inventory, const std::string& filename = "gui/inventory_state.json");
    static void loadFromFile(Inventory& inventory, const std::string& filename = "gui/inventory_state.json");
};

#endif