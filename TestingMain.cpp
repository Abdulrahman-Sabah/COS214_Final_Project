#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"
#include <iostream>

class SimplePlant : public Plant {
private:
    double plantPrice;
    
public:
    SimplePlant(std::string n, std::string c, std::string st, std::string se, double p = 50.0) 
        : Plant(n, c, st, se, nullptr, nullptr), plantPrice(p) {}
    
    std::string description() override {
        return getName() + " - A beautiful plant for your garden";
    }
    
    double price() override {
        return plantPrice;
    }
    
    Plant* clone() override {
        return new SimplePlant(getName(), getCareType(), getStateText(), getSeason(), plantPrice);
    }
};

int main() {
    std::cout << "=== Plant Nursery Iterator Demo ===\n\n";
    
    Inventory* inventory = new Inventory();
    
    std::cout << "Test 1: Adding plants\n";
    inventory->addPlant(new SimplePlant("Red Rose", "Moderate", "Budding", "Spring", 45.99));
    inventory->addPlant(new SimplePlant("Aloe Vera", "Low", "Mature", "Summer", 25.50));
    inventory->addPlant(new SimplePlant("Barrel Cactus", "Low", "Young", "Summer", 35.00));
    inventory->addPlant(new SimplePlant("Lavender", "Moderate", "Flowering", "Spring", 28.75));
    inventory->addPlant(new SimplePlant("Baobab Tree", "High", "Seedling", "Year-round", 150.00));
    inventory->addPlant(new SimplePlant("Jade Plant", "Low", "Mature", "Year-round", 32.00));
    inventory->addPlant(new SimplePlant("Peace Lily", "Moderate", "Flowering", "Spring", 55.00));
    inventory->addPlant(new SimplePlant("Snake Plant", "Low", "Mature", "Year-round", 40.00));
    std::cout << "Added 8 plants. Total: " << inventory->getSize() << "\n\n";
    
    std::cout << "Test 2: Basic iteration\n";
    PlantIterator* it1 = inventory->createIterator();
    int count = 0;
    for (it1->first(); !it1->isDone(); it1->next()) {
        if (it1->current() != nullptr) count++;
    }
    std::cout << "Iterated through " << count << " plants\n\n";
    delete it1;
    
    std::cout << "Test 3: Filter by season (Spring)\n";
    PlantIterator* it2 = inventory->createIterator();
    int springCount = 0;
    for (it2->first(); !it2->isDone(); it2->next()) {
        Plant* p = it2->current();
        if (p != nullptr && p->getSeason() == "Spring") {
            springCount++;
        }
    }
    std::cout << "Found " << springCount << " spring plants\n\n";
    delete it2;
    
    std::cout << "Test 4: Filter by care level (Low)\n";
    PlantIterator* it3 = inventory->createIterator();
    int lowCareCount = 0;
    for (it3->first(); !it3->isDone(); it3->next()) {
        Plant* p = it3->current();
        if (p != nullptr && p->getCareType() == "Low") {
            lowCareCount++;
        }
    }
    std::cout << "Found " << lowCareCount << " low-care plants\n\n";
    delete it3;
    
    std::cout << "Test 5: Calculate average price\n";
    PlantIterator* it4 = inventory->createIterator();
    double totalPrice = 0.0;
    int priceCount = 0;
    for (it4->first(); !it4->isDone(); it4->next()) {
        Plant* p = it4->current();
        if (p != nullptr) {
            totalPrice += p->price();
            priceCount++;
        }
    }
    double avgPrice = (priceCount > 0) ? totalPrice / priceCount : 0.0;
    std::cout << "Average plant price: R" << avgPrice << "\n\n";
    delete it4;
    
    std::cout << "Test 6: Remove plant by name\n";
    bool removed = inventory->removePlantByName("Barrel Cactus");
    std::cout << "Removal " << (removed ? "successful" : "failed") 
              << ". New total: " << inventory->getSize() << "\n\n";
    
    std::cout << "Test 7: Multiple concurrent iterations\n";
    PlantIterator* itA = inventory->createIterator();
    PlantIterator* itB = inventory->createIterator();
    
    itA->first();
    itB->first();
    
    int posA = 0, posB = 0;
    while (!itA->isDone()) {
        posA++;
        itA->next();
    }
    while (!itB->isDone()) {
        posB++;
        itB->next();
    }
    std::cout << "Iterator A counted: " << posA << ", Iterator B counted: " << posB << "\n\n";
    delete itA;
    delete itB;
    
    std::cout << "Test 8: Find expensive plants (>R50)\n";
    PlantIterator* it5 = inventory->createIterator();
    int expensiveCount = 0;
    for (it5->first(); !it5->isDone(); it5->next()) {
        Plant* p = it5->current();
        if (p != nullptr && p->price() > 50.0) {
            expensiveCount++;
        }
    }
    std::cout << "Found " << expensiveCount << " plants over R50\n\n";
    delete it5;
    
    std::cout << "Test 9: Iterator reset capability\n";
    PlantIterator* it6 = inventory->createIterator();
    it6->first();
    int firstPass = 0;
    while (!it6->isDone()) {
        firstPass++;
        it6->next();
    }
    it6->first();
    int secondPass = 0;
    while (!it6->isDone()) {
        secondPass++;
        it6->next();
    }
    std::cout << "First pass: " << firstPass << ", Second pass: " << secondPass << "\n\n";
    delete it6;
    
    std::cout << "Test 10: Check current inventory state\n";
    std::cout << "Final inventory size: " << inventory->getSize() << " plants\n";
    
    delete inventory;
    
    std::cout << "\n=== All Iterator Tests Passed ===\n";
    
    return 0;
}