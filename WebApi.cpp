#include "WebAPI.h"
#include "BasicPlant.h"  // Needed for BasicPlant
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>

WebAPI::WebAPI(Inventory* inv) : inventory(inv) {}

// Get plants from the REAL C++ inventory
std::string WebAPI::getPlantsJSON() {
    std::stringstream json;
    json << "{\"plants\":[";
    
    PlantIterator* it = inventory->createIterator();
    bool first = true;
    
    for (it->first(); !it->isDone(); it->next()) {
        Plant* plant = it->current();
        if (plant) {
            if (!first) json << ",";
            json << "{";
            json << "\"name\":\"" << plant->getName() << "\",";
            json << "\"careType\":\"" << plant->getCareType() << "\",";
            json << "\"state\":\"" << plant->getStateText() << "\",";
            json << "\"season\":\"" << plant->getSeason() << "\",";
            json << "\"price\":" << plant->price();
            json << "}";
            first = false;
        }
    }
    
    delete it;
    json << "]}";
    return json.str();
}

// Add plant to the REAL C++ inventory
bool WebAPI::addPlantToInventory(const std::string& name, const std::string& careType, 
                                const std::string& state, const std::string& season, double price) {
    std::cout << "🌱 Adding plant to C++ inventory: " << name << std::endl;
    
    // Use BasicPlant for web-created plants
    Plant* newPlant = new BasicPlant(name, "Web-added plant", price, careType, state, season);
    inventory->addPlant(newPlant);
    
    // Save the updated REAL inventory
    InventorySerializer::saveToFile(*inventory, "gui/inventory_state.json");
    std::cout << "💾 Saved REAL inventory with " << inventory->getSize() << " plants" << std::endl;
    
    return true;
}

// Remove plant from REAL C++ inventory
bool WebAPI::removePlantFromInventory(const std::string& name) {
    bool success = inventory->removePlantByName(name);
    if (success) {
        InventorySerializer::saveToFile(*inventory, "gui/inventory_state.json");
    }
    return success;
}

// Simple file-based API implementation
void startWebServer(Inventory* inventory) {
    WebAPI webAPI(inventory);
    
    std::cout << "🌿 WebAPI Server Started!" << std::endl;
    
    // Initial load from file
    InventorySerializer::loadFromFile(*inventory, "gui/inventory_state.json");
    std::cout << "📊 Loaded " << inventory->getSize() << " plants from file" << std::endl;
    
    std::cout << "👀 Will reload file every 5 seconds..." << std::endl;
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        
        std::cout << "🔄 Reloading inventory from file..." << std::endl;
        InventorySerializer::loadFromFile(*inventory, "gui/inventory_state.json");
        std::cout << "📊 Now have " << inventory->getSize() << " plants" << std::endl;
    }
}
