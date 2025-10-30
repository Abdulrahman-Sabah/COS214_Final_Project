#include "InventorySerializer.h"
#include "BasicPlant.h"
#include "Rose.h"
#include "Cactus.h" 
#include "Lavender.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

void InventorySerializer::saveToFile(Inventory& inventory, const std::string& filename)
{
    std::cout << "💾 STEP: Saving to file: " << filename << std::endl;
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ FAILED to open file for writing: " << filename << std::endl;
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
            // 🆕 ADD TYPE FIELD
            file << "\"type\":\"" << plant->getType() << "\",";
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

// ADD THIS DEFINITION OUTSIDE THE CLASS
void InventorySerializer::initializeInventory(Inventory& inventory) {
    std::cout << "🎯 Initializing inventory with default plants" << std::endl;
    
    inventory.clear();
    inventory.addPlant(new Rose());
    inventory.addPlant(new Cactus());  
    inventory.addPlant(new Lavender());
    
    std::cout << "✅ Initialized " << inventory.getSize() << " default plants" << std::endl;
}

// ADD HELPER FUNCTION FIRST (before loadFromFile):
std::string InventorySerializer::extractJSONField(const std::string& content, const std::string& field, size_t& pos) {
    size_t start = content.find(field, pos);
    if (start == std::string::npos) return "";
    start = content.find("\"", start + field.length()) + 1;
    size_t end = content.find("\"", start);
    return content.substr(start, end - start);
}

// MODIFY loadFromFile() to handle specific types:
void InventorySerializer::loadFromFile(Inventory& inventory, const std::string& filename) {
    std::cout << "🔍 STEP 1: Looking for file: " << filename << std::endl;
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "❌ FILE NOT FOUND: " << filename << std::endl;
        std::cout << "🎯 Creating new file with default plants..." << std::endl;
        
        initializeInventory(inventory);
        saveToFile(inventory, filename);
        
        std::cout << "✅ File should now be created: " << filename << std::endl;
        return;
    }
    
    std::cout << "✅ File found, reading content..." << std::endl;
    
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    
    std::cout << "📄 File content length: " << content.length() << " characters" << std::endl;
    
    if (content.empty()) {
        std::cout << "❌ FILE IS EMPTY - initializing..." << std::endl;
        initializeInventory(inventory);
        saveToFile(inventory, filename);
        return;
    }
    
    std::cout << "📄 First 100 chars: " << content.substr(0, 100) << std::endl;
    
    std::cout << "💾 Loading from: " << filename << std::endl;
    
    // Clear existing inventory
    inventory.clear();
    
    // Simple JSON parsing - look for plant arrays
    size_t pos = 0;
    int plantsLoaded = 0;
    
    while ((pos = content.find("\"name\"", pos)) != std::string::npos) {
        // Extract plant data
        std::string type = extractJSONField(content, "\"type\"", pos);
        std::string name = extractJSONField(content, "\"name\"", pos);
        std::string careType = extractJSONField(content, "\"careType\"", pos);
        std::string state = extractJSONField(content, "\"state\"", pos);
        std::string season = extractJSONField(content, "\"season\"", pos);
        
        // Extract price
        size_t priceStart = content.find("\"price\"", pos);
        priceStart = content.find(":", priceStart + 7) + 1;
        size_t priceEnd = content.find_first_of(",}", priceStart);
        double price = std::stod(content.substr(priceStart, priceEnd - priceStart));
        
        // Create plant with properties from JSON
        Plant* newPlant = nullptr;
        if (type == "Rose") {
            Rose* rose = new Rose();
            rose->setName(name);
            rose->setCareType(careType);
            rose->setStateText(state);
            rose->setSeason(season);
            rose->setPrice(price);
            newPlant = rose;
        } else if (type == "Cactus") {
            Cactus* cactus = new Cactus();
            cactus->setName(name);
            cactus->setCareType(careType);
            cactus->setStateText(state);
            cactus->setSeason(season);
            cactus->setPrice(price);
            newPlant = cactus;
        } else if (type == "Lavender") {
            Lavender* lavender = new Lavender();
            lavender->setName(name);
            lavender->setCareType(careType);
            lavender->setStateText(state);
            lavender->setSeason(season);
            lavender->setPrice(price);
            newPlant = lavender;
        } else {
            newPlant = new BasicPlant(name, "Loaded from file", price, careType, state, season);
        }
        
        inventory.addPlant(newPlant);
        plantsLoaded++;
        pos = priceEnd;
    }
    
    // 🆕 If no plants were found in JSON, initialize defaults
    if (plantsLoaded == 0) {
        std::cout << "📁 No plants found in JSON, initializing defaults" << std::endl;
        initializeInventory(inventory);
        saveToFile(inventory, filename);
    }
    
    std::cout << "💾 Loaded " << plantsLoaded << " plants from " << filename << std::endl;
}