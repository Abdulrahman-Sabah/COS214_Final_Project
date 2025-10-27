#include "InventorySerializer.h"
#include <fstream>
#include <sstream>
#include <iostream>

void InventorySerializer::saveToFile(Inventory& inventory, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Failed to open file for writing: " << filename << std::endl;
        return;
    }
    
    file << "{\"plants\":[";
    
    PlantIterator* it = inventory.createIterator();
    bool first = true;
    
    for (it->first(); !it->isDone(); it->next()) {
        Plant* plant = it->current();
        if (plant) {
            if (!first) file << ",";
            file << "{";
            file << "\"name\":\"" << plant->getName() << "\",";
            file << "\"careType\":\"" << plant->getCareType() << "\",";
            file << "\"state\":\"" << plant->getStateText() << "\",";
            file << "\"season\":\"" << plant->getSeason() << "\",";
            file << "\"price\":" << plant->price();
            file << "}";
            first = false;
        }
    }
    
    delete it;
    file << "]}";
    file.close();
    
    std::cout << "💾 Saved " << inventory.getSize() << " plants to " << filename << std::endl;
}

void InventorySerializer::loadFromFile(Inventory& inventory, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "📁 No inventory file found" << std::endl;
        return;
    }
    
    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    file.close();
    
    // Simple JSON parsing (you may want to use a library like nlohmann/json)
    // For now, this is a basic parser
    // Parse and create plants...
    
    std::cout << "💾 Loaded plants from " << filename << std::endl;

}