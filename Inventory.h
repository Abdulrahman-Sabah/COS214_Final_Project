#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"
#include "PlantIterator.h"
#include <vector>


class Inventory {
private:
    std::vector<Plant*> plants;
public:

    Inventory();
    ~Inventory();
    void addPlant(Plant* p);
    bool removePlant(Plant* p);
    Plant* removePlantByName(const std::string& name);
    size_t getSize() const;
    PlantIterator* createIterator();
    std::vector<Plant*>& getPlants();
    void displayAll();
};

#endif
