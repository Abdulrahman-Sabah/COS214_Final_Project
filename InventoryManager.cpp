// #include "InventoryManager.h"

// // Initialize static member
// InventoryManager* InventoryManager::instance = nullptr;

// InventoryManager* InventoryManager::getInstance() {
//     if (instance == nullptr) {
//         instance = new InventoryManager();
//     }
//     return instance;
// }

// Inventory& InventoryManager::getInventory() {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
//     return inventory;
// }

// // Add const version for const methods
// const Inventory& InventoryManager::getInventory() const {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
//     return inventory;
// }

// void InventoryManager::addPlant(Plant* plant) {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
//     inventory.addPlant(plant);
// }

// bool InventoryManager::removePlant(Plant* plant) {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
//     return inventory.removePlant(plant);
// }

// size_t InventoryManager::getSize() const {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
//     return inventory.getSize();
// }

// void InventoryManager::clearInventory() {
//     std::lock_guard<std::mutex> lock(inventoryMutex);
    
//     // Properly delete all plants to prevent memory leaks
//     PlantIterator* it = inventory.createIterator();
//     for (it->first(); !it->isDone(); it->next()) {
//         Plant* plant = it->current();
//         if (plant) {
//             delete plant;
//         }
//     }
//     delete it;
    
//     // Clear the vector
//     std::vector<Plant*>& plants = inventory.getPlants();
//     plants.clear();
// }