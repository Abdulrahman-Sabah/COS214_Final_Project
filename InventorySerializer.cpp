#include "InventorySerializer.h"
# include "BasicPlant.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

void InventorySerializer::saveToFile(Inventory& inventory, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Failed to open file for writing: " << filename << std::endl;
        return;
    }
    
    std::cout << "💾 Saving to: " << filename << std::endl;
    std::cout << "📁 Current dir: " << std::filesystem::current_path() << std::endl;
    

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
        std::cout << "📁 No inventory file found: " << filename << std::endl;
        return;
    }
    
    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    file.close();
    
    std::cout << "💾 Loading from: " << filename << std::endl;
    std::cout << "📄 File content size: " << content.length() << " characters" << std::endl;
    
    // Clear existing inventory
    // Note: You might need to implement inventory.clear() or handle this differently
    // For now, we'll just add to existing inventory
    
    // Simple JSON parsing - look for plant arrays
    size_t pos = 0;
    int plantsLoaded = 0;
    
    while ((pos = content.find("\"name\"", pos)) != std::string::npos) {
        // Extract plant data
        size_t nameStart = content.find("\"", pos + 6) + 1;
        size_t nameEnd = content.find("\"", nameStart);
        std::string name = content.substr(nameStart, nameEnd - nameStart);
        
        // Find careType
        size_t careStart = content.find("\"careType\"", nameEnd);
        careStart = content.find("\"", careStart + 10) + 1;
        size_t careEnd = content.find("\"", careStart);
        std::string careType = content.substr(careStart, careEnd - careStart);
        
        // Find state
        size_t stateStart = content.find("\"state\"", careEnd);
        stateStart = content.find("\"", stateStart + 7) + 1;
        size_t stateEnd = content.find("\"", stateStart);
        std::string state = content.substr(stateStart, stateEnd - stateStart);
        
        // Find season
        size_t seasonStart = content.find("\"season\"", stateEnd);
        seasonStart = content.find("\"", seasonStart + 8) + 1;
        size_t seasonEnd = content.find("\"", seasonStart);
        std::string season = content.substr(seasonStart, seasonEnd - seasonStart);
        
        // Find price
        size_t priceStart = content.find("\"price\"", seasonEnd);
        priceStart = content.find(":", priceStart + 7) + 1;
        size_t priceEnd = content.find_first_of(",}", priceStart);
        double price = std::stod(content.substr(priceStart, priceEnd - priceStart));
        
        // Create and add plant (using BasicPlant as a generic plant type)
        Plant* newPlant = new BasicPlant(name, "Loaded from file", price, careType, state, season);
        inventory.addPlant(newPlant);
        plantsLoaded++;
        
        pos = priceEnd;
    }
    
    std::cout << "💾 Loaded " << plantsLoaded << " plants from " << filename << std::endl;
}