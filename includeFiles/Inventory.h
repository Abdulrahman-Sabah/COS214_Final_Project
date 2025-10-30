/**
 * @file Inventory.h
 * @brief Header file for the Inventory management class
 * @author COS214 Students
 * @date 2024
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"
#include "PlantIterator.h"
#include <vector>

/**
 * @class Inventory
 * @brief Manages a collection of plants with iterator support
 * 
 * This class provides functionality to store, manage, and iterate through
 * a collection of plants. It implements the Iterator pattern to allow
 * traversal of the plant collection.
 */
class Inventory {
private:
    std::vector<Plant*> plants; ///< Vector storing all plants in inventory

public:
    /**
     * @brief Default constructor
     */
    Inventory();

    /**
     * @brief Destructor that cleans up all plants
     */
    ~Inventory();

    /**
     * @brief Adds a plant to the inventory
     * @param p Pointer to the plant to add
     */
    void addPlant(Plant* p);

    /**
     * @brief Removes a specific plant from the inventory
     * @param p Pointer to the plant to remove
     * @return True if plant was found and removed, false otherwise
     */
    bool removePlant(Plant* p);

    /**
     * @brief Removes a plant by name from the inventory
     * @param name Name of the plant to remove
     * @return True if plant was found and removed, false otherwise
     */
    bool removePlantByName(const std::string& name);

    /**
     * @brief Gets the number of plants in inventory
     * @return Size of the inventory
     */
    size_t getSize() const;

    /**
     * @brief Creates an iterator for traversing the inventory
     * @return Pointer to a PlantIterator for this inventory
     */
    PlantIterator* createIterator();

    /**
     * @brief Gets reference to the plants vector
     * @return Reference to the vector of plants
     */
    std::vector<Plant*>& getPlants();

    /**
     * @brief Displays all plants in the inventory
     */
    void displayAll();

    bool hasPlant(Plant* p);
    
};

#endif