#ifndef WEBAPI_CPP_DOC
/**
 * @file WebApi.cpp
 * @brief Lightweight bridge between the C++ `Inventory` model and a simple
 *        JSON/file-based web API used by the demo GUI.
 *
 * Provides helpers to serialize the Inventory to JSON and simple functions
 * to initialize a demo inventory and run a small file-based reloader loop.
 */
#define WEBAPI_CPP_DOC
#endif

#include "WebAPI.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

#include "BasicPlant.h" // Needed for BasicPlant
#include "Cactus.h"
#include "Lavender.h"
#include "Rose.h"

WebAPI::WebAPI(Inventory *inv) : inventory(inv) {}

std::string WebAPI::getPlantsJSON() {
  std::stringstream json;
  json << "{\"plants\":[";

  PlantIterator *it = inventory->createIterator();
  bool first = true;

  for (it->first(); !it->isDone(); it->next()) {
    Plant *plant = it->current();
    if (plant) {
      if (!first)
        json << ",";
      json << "{";
      json << "\"type\":\"" << plant->getType() << "\",";
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

bool WebAPI::addPlantToInventory(const std::string &name,
                                 const std::string &careType,
                                 const std::string &state,
                                 const std::string &season, double price) {
  std::cout << "Adding plant to C++ inventory: " << name << std::endl;

  Plant *newPlant =
      new BasicPlant(name, "Web-added plant", price, careType, state, season);
  inventory->addPlant(newPlant);

  InventorySerializer::saveToFile(*inventory, "gui/inventory_state.json");
  std::cout << "Saved REAL inventory with " << inventory->getSize()
            << " plants" << std::endl;

  return true;
}

bool WebAPI::removePlantFromInventory(const std::string &name) {
  bool success = inventory->removePlantByName(name);
  if (success) {
    InventorySerializer::saveToFile(*inventory, "gui/inventory_state.json");
  }
  return success;
}

void initializeInventory(Inventory &inventory) {
  inventory.addPlant(new Rose());     // Uses Rose's default setup
  inventory.addPlant(new Cactus());   // Uses your Cactus default setup
  inventory.addPlant(new Lavender()); // Uses Lavender's default setup

  InventorySerializer::saveToFile(inventory, "gui/inventory_state.json");
}

// Simple file-based API implementation
void startWebServer(Inventory *inventory) {
  WebAPI webAPI(inventory);

  std::cout << "WebAPI Server Started!" << std::endl;

  std::cout << " Created " << inventory->getSize() << " specific plant types"
            << std::endl;

  std::cout << "Will reload file every 5 seconds..." << std::endl;

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Reloading inventory from file..." << std::endl;
    InventorySerializer::loadFromFile(*inventory, "gui/inventory_state.json");
    std::cout << "Now have " << inventory->getSize() << " plants"
              << std::endl;
  }
}
