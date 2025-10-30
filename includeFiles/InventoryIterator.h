#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H

#include "PlantIterator.h"
#include <vector>

class InventoryIterator : public PlantIterator {
private:
    std::vector<Plant*>& plants;
    size_t currentIndex;

public:

    InventoryIterator(std::vector<Plant*>& plantList);

    ~InventoryIterator();

    void first() override;
    void next() override;
    bool isDone() override;
    Plant* current() override;
};

#endif
