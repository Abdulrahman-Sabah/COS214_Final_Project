// #ifndef INVENTORYMANAGER_H
// #define INVENTORYMANAGER_H

// #include "Inventory.h"
// #include <mutex>

// class InventoryManager {
// private:
//     static InventoryManager* instance;
//     Inventory inventory;
//     mutable std::mutex inventoryMutex;  // Change to mutable
    
//     // Private constructor to prevent direct instantiation
//     InventoryManager() = default;

// public:
//     // Static method to get the singleton instance
//     static InventoryManager* getInstance();
    
//     // Thread-safe inventory access methods
//     Inventory& getInventory();
//     const Inventory& getInventory() const;  // Add const version
//     void addPlant(Plant* plant);
//     bool removePlant(Plant* plant);
//     size_t getSize() const;
//     void clearInventory();
    
//     // Prevent copying
//     InventoryManager(const InventoryManager&) = delete;
//     InventoryManager& operator=(const InventoryManager&) = delete;
// };

// #endif