/**
 * @file InventoryIterator.h
 * @brief Concrete iterator for traversing Inventory collections
 * @author COS214 Students
 * @date 2024
 */

#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "PlantIterator.h"
#include <vector>

/**
 * @class InventoryIterator
 * @brief Concrete iterator implementation for Inventory plant collections
 * 
 * This class provides a concrete implementation of the PlantIterator interface
 * specifically for traversing plant collections stored in an Inventory object.
 */
class InventoryIterator : public PlantIterator {
private:
    std::vector<Plant*>& plants; ///< Reference to the plants vector
    size_t currentIndex; ///< Current position in the iteration

public:
    /**
     * @brief Constructor that initializes the iterator with a plant list
     * @param plantList Reference to the vector of plants to iterate over
     */
    InventoryIterator(std::vector<Plant*>& plantList);

    /**
     * @brief Destructor for cleanup
     */
    ~InventoryIterator();

    /**
     * @brief Resets the iterator to the first element
     */
    void first() override;
    
    /**
     * @brief Moves the iterator to the next element
     */
    void next() override;
    
    /**
     * @brief Checks if the iterator has reached the end
     * @return True if no more elements, false otherwise
     */
    bool isDone() override;
    
    /**
     * @brief Gets the current plant element
     * @return Pointer to the current Plant object
     */
    Plant* current() override;
};

#endif
