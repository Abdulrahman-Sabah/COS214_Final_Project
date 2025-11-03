#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

/**
 * @file InventoryIterator.h
 * @brief Iterator over a list of plants.
 */

#include <vector>
#include "PlantIterator.h"

/**
 * @class InventoryIterator
 * @brief Concrete iterator for plant collections.
 */
class InventoryIterator : public PlantIterator {
private:
    std::vector<Plant*>& plants;
    size_t currentIndex;

public:
    /**
     * @brief Constructor
     * @param plantList Reference to plant list
     */
    InventoryIterator(std::vector<Plant*>& plantList);

    /// Destructor
    ~InventoryIterator();

    /// Move to first element
    void first() override;

    /// Move to next element
    void next() override;

    /// @return True if reached end
    bool isDone() override;

    /// @return Current plant pointer
    Plant* current() override;
};

#endif
