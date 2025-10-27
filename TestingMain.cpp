#include "Inventory.h"
#include "PlantIterator.h"
#include "Plant.h"
#include "Rose.h"
#include "CareScheduleObserver.h"
#include "BasicPlant.h"
#include "PlantDecorations.h"
#include <iostream>
#include <iomanip>
#include "PotDecorator.h"
#include "CardDecorator.h"
#include "WrapDecorator.h"
#include <string>
#include <vector>
#include "Plant.h"
#include "PlantLifeCycleState.h"
#include "SeedlingState.h"
#include "GrowingState.h"
#include "DormantState.h"
#include "MatureState.h"
#include "SellingState.h"
#include "DeadState.h"
#include "Creator.h"
#include "RoseCreator.h"
#include "CactusCreator.h"
#include "LavenderCreator.h"
#include "Cactus.h"
#include "Lavender.h"
#include "Lavender.h"
#include "Rose.h"
#include "Plant.h"
#include "MoveToSales.h"
#include "Command.h"
#include "ScheduleDelivery.h"
#include "ApplyFertilizer.h"
#include "AddWater.h"

using namespace std;
  
const string ANSI_RED = "\u001b[31;1m";
const string ANSI_GREEN = "\u001b[32;1m";
const string ANSI_BLUE = "\033[0;34m";
const string ANSI_RESET = "\u001b[0m";


bool assertState(const std::string& testName, bool condition) {
    if (condition) {
        std::cout << ANSI_GREEN << "PASS: " << testName << ANSI_RESET << std::endl;
        return true;
    } else {
        std::cout << ANSI_RED << "FAIL: " << testName << " , Condition failed, it was false\n" << ANSI_RESET;
        return false;
    }
}


template<typename T>
bool assertStateEqual(const std::string& testName, const T& expected, const T& actual) {
    if (expected == actual) {
        std::cout << ANSI_GREEN << "PASS: " << testName << ANSI_RESET << std::endl;
        return true;
    } 
    else {
        std::cout << ANSI_RED << "FAIL: " << testName << " What is expected: " << expected 
        << ", What we got: " << actual << "]\n" << ANSI_RESET;
        return false;
    }
}

void initialState() {  
    std::cout << "Testing Initial State\n";
    Plant* hMPlant = new Rose();
    PlantLifeCycleState* state = hMPlant->getLifeCycle();
    assertState("State is not null", state);
    if (state) assertStateEqual("Testing for Seedling", std::string("Seedling"), state->name());
    delete hMPlant;
}


void seedlingTest() {
    std::cout << "Testing Seedling\n";
    Plant* hMPlant = new Rose();
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("New state = Growing", std::string("Growing"), newState->name());
    delete hMPlant;
}

void growingTest() {
    std::cout << "Testing Growing\n";
    Plant* hMPlant = new Rose();
    hMPlant->setLifeCycle(new GrowingState());
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("New state = Dormant", std::string("Dormant"), newState->name());
    delete hMPlant;
}

void dormantTest() {
    std::cout << "Testing Dormant\n";
    std::cout << "Growing boolean variable is true\n";
    {
        Plant* hMPlant = new Rose();
        DormantState* d = new DormantState();
        hMPlant->setLifeCycle(d);
        d->setGrowing(true);
        hMPlant->getLifeCycle()->advance(hMPlant);
        PlantLifeCycleState* newState = hMPlant->getLifeCycle();
        assertState("New state is not null", newState);
        if (newState) assertStateEqual("New state = Growing", std::string("Growing"), newState->name());
        delete hMPlant;
    }
    std::cout << "Growing boolean variable is false\n";
    {
        Plant* hMPlant = new Rose();
        DormantState* d = new DormantState();
        hMPlant->setLifeCycle(d);
        d->setGrowing(false);
        hMPlant->getLifeCycle()->advance(hMPlant);
        PlantLifeCycleState* newState = hMPlant->getLifeCycle();
        assertState("New state is not null", newState);
        if (newState) assertStateEqual("New state = Mature", std::string("Mature"), newState->name());
        delete hMPlant;
    }
}

void matureTest() {
    std::cout << "Testing Mature\n";
    Plant* hMPlant = new Rose();
    hMPlant->setLifeCycle(new MatureState());
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("New state = Selling", std::string("Selling"), newState->name());
    delete hMPlant;
}

void sellingTest() {
    std::cout << "Testing Selling\n";
    Plant* hMPlant = new Rose();
    hMPlant->setLifeCycle(new SellingState());
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("No new State", std::string("Selling"), newState->name());
    delete hMPlant;
}

void deadTest() {
    std::cout << "Testing Dead\n";
    Plant* hMPlant = new Rose();
    hMPlant->setLifeCycle(new DeadState());
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("New state = Dead", std::string("Dead"), newState->name());
    delete hMPlant;
}

void deadfromMatureTest() {
    std::cout << "Testing Dead from Mature\n";
    Plant* hMPlant = new Rose();
    hMPlant->setLifeCycle(new MatureState());
    MatureState* matureState = dynamic_cast<MatureState*>(hMPlant->getLifeCycle());
    if (matureState) matureState->setDead(true);
    hMPlant->getLifeCycle()->advance(hMPlant);
    PlantLifeCycleState* newState = hMPlant->getLifeCycle();
    assertState("New state is not null", newState);
    if (newState) assertStateEqual("New state = Dead", std::string("Dead"), newState->name());
    delete hMPlant;

}

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

int main() 
{

    std::cout << "========== Factory Method Testing ==========\n" << std::endl;

    RoseCreator roseCreator;
    CactusCreator cactusCreator;
    LavenderCreator lavenderCreator;

    Plant* rose = roseCreator.factoryMethod();
    Plant* cactus = cactusCreator.factoryMethod();
    Plant* lavender = lavenderCreator.factoryMethod();

    delete rose;
    delete cactus;
    delete lavender;

    std::cout << "========== End of Factory Method Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "========== Plant Class Testing ==========\n" << std::endl;

    Cactus cactusPlant;
    Lavender lavenderPlant;
    Rose rosePlant;

    std::cout << "Description: " << cactusPlant.description() << std::endl;
    std::cout << "Care Type: " << cactusPlant.getCareType() << std::endl;
    std::cout << "State: " << cactusPlant.getStateText() << std::endl;
    std::cout << "Season: " << cactusPlant.getSeason() << std::endl;
    std::cout << "Price: R" << cactusPlant.price() << "\n" << std::endl;

    std::cout << "Name: " << lavenderPlant.getName() << std::endl;
    std::cout << "Description: " << lavenderPlant.description() << std::endl;
    std::cout << "Care Type: " << lavenderPlant.getCareType() << std::endl;
    std::cout << "State: " << lavenderPlant.getStateText() << std::endl;
    std::cout << "Season: " << lavenderPlant.getSeason() << std::endl;
    std::cout << "Price: R" << lavenderPlant.price() << "\n" << std::endl;

    std::cout << "Name: " << rosePlant.getName() << std::endl;
    std::cout << "Description: " << rosePlant.description() << std::endl;
    std::cout << "Care Type: " << rosePlant.getCareType() << std::endl;
    std::cout << "State: " << rosePlant.getStateText() << std::endl;
    std::cout << "Season: " << rosePlant.getSeason() << std::endl;
    std::cout << "Price: R" << rosePlant.price() << "\n" << std::endl;

    std::cout << "========== Clone Tests ==========\n" << std::endl;

    Plant* clonedCactus = cactusPlant.clone();
    std::cout << "--- Cactus Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedCactus->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedCactus->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedCactus->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedCactus->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedCactus->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedCactus->price() << "\n" << std::endl;

    Plant* clonedLavender = lavenderPlant.clone();
    std::cout << "--- Lavender Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedLavender->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedLavender->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedLavender->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedLavender->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedLavender->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedLavender->price() << "\n" << std::endl;

    Plant* clonedRose = rosePlant.clone();
    std::cout << "--- Rose Clone ---" << std::endl;
    std::cout << "Cloned Name: " << clonedRose->getName() << std::endl;
    std::cout << "Cloned Description: " << clonedRose->description() << std::endl;
    std::cout << "Cloned Care Type: " << clonedRose->getCareType() << std::endl;
    std::cout << "Cloned State: " << clonedRose->getStateText() << std::endl;
    std::cout << "Cloned Season: " << clonedRose->getSeason() << std::endl;
    std::cout << "Cloned Price: R" << clonedRose->price() << "\n" << std::endl;

    delete clonedCactus;
    delete clonedLavender;
    delete clonedRose;

    std::cout << "========== End of Clone Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "\n========== End of Plant Class Test ==========" << std::endl;

    std::cout << std::endl;

    std::cout << "========== Command Pattern Testing ==========\n" << std::endl;

    MoveToSales moveCommand("Plant-001");
    ScheduleDelivery scheduleCommand("Order-ABC123");
    ApplyFertilizer fertilizerCommand("Plant-002");
    AddWater waterCommand("Plant-003");

    std::cout << "Command Type: " << moveCommand.getType() << std::endl;
    std::cout << "Command Data: " << moveCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << scheduleCommand.getType() << std::endl;
    std::cout << "Command Data: " << scheduleCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << fertilizerCommand.getType() << std::endl;
    std::cout << "Command Data: " << fertilizerCommand.getData() << "\n" << std::endl;

    std::cout << "Command Type: " << waterCommand.getType() << std::endl;
    std::cout << "Command Data: " << waterCommand.getData() << "\n" << std::endl;

    std::cout << "========== End of Command Test ==========" << std::endl;
    std::cout << std::endl;

    std::cout << "===========State Pattern testing==================\n";
    std::cout << ANSI_BLUE << "=========================================\n";
    std::cout  << "TESTING PLANT LIFE CYCLE STATE\n";
    std::cout << "=========================================\n" << ANSI_RESET;
    initialState();
    std::cout << "=========================================\n";
    seedlingTest();
    std::cout << "=========================================\n";
    growingTest();
    std::cout << "=========================================\n";
    dormantTest();
    std::cout << "=========================================\n";
    matureTest();
    std::cout << "=========================================\n";
    sellingTest();
    std::cout << "=========================================\n";
    deadTest();
    std::cout << "=========================================\n";
    deadfromMatureTest();
    std::cout << ANSI_BLUE << "=========================================\n";
    std::cout << ANSI_BLUE << "ALL TESTS COMPLETED SUCCESSFULLY\n" << ANSI_RESET;
    std::cout << ANSI_BLUE << "=========================================\n";
  
  
    cout << "=== PLANT OBSERVER PATTERN TEST ===" << endl;
    cout << "Creating a rose plant..." << endl;
    
    Rose* rose = new Rose();
    
    CareSchedulerObserver* scheduler = new CareSchedulerObserver();
    
    cout << "\nAttaching CareSchedulerObserver to the rose..." << endl;
    rose->attach(scheduler);
    
    cout << "\n--- Testing Notifications ---" << endl;
    
    cout << "\n1. Changing plant state:" << endl;
    rose->setStateText("Flowering");
    
    cout << "\n2. Changing season:" << endl;
    rose->setSeason("Summer");
    
    cout << "\n3. Changing care type:" << endl;
    rose->setCareType("High");
    
    cout << "\n4. Changing name (no observer for this):" << endl;
    rose->setName("Red Rose");
    cout << "Name changed to: " << rose->getName() << " (no notification expected)" << endl;
    
    cout << "\n5. Detaching observer and making changes:" << endl;
    rose->detach(scheduler);
    rose->setStateText("Mature");
    cout << "State changed to Mature (no notification expected - observer detached)" << endl;
    
    cout << "\n6. Re-attaching observer:" << endl;
    rose->attach(scheduler);
    rose->setSeason("Autumn");
    
    cout << "\n--- Testing Plant Information ---" << endl;
    cout << "Plant Description: " << rose->description() << endl;
    cout << "Plant Price: $" << rose->price() << endl;
    
    cout << "\n=== CLEANUP ===" << endl;
    delete rose;
    delete scheduler;
    
    cout << "Test completed successfully!" << endl;

    cout << "=== PLANT DECORATOR PATTERN TEST ===\n" << endl;
    
    cout << "TEST 1: Basic Plant" << endl;
    cout << "-------------------" << endl;
    Plant* basicRose = new BasicPlant("Rose", "Beautiful red rose", 15.99);
    cout << "Description: " << basicRose->description() << endl;
    cout << "Price: $" << fixed << setprecision(2) << basicRose->price() << endl;
    cout << "Name: " << basicRose->getName() << endl;
    cout << endl;
    
    cout << "TEST 2: Plant with Pot Decorator" << endl;
    cout << "-------------------------------" << endl;
    Plant* potRose = new PotDecorator(basicRose, "Ceramic", 8.99);
    cout << "Description: " << potRose->description() << endl;
    cout << "Price: $" << potRose->price() << endl;
    cout << "Name: " << potRose->getName() << endl;
    cout << endl;
    
    cout << "TEST 3: Plant with Multiple Decorations" << endl;
    cout << "--------------------------------------" << endl;
    Plant* basicTulip = new BasicPlant("Tulip", "Yellow spring tulip", 12.50);
    Plant* tulipWithPot = new PotDecorator(basicTulip, "Terracotta", 6.50);
    Plant* tulipWithCard = new CardDecorator(tulipWithPot, "Get Well Soon!", 3.25);
    Plant* giftTulip = new WrapDecorator(tulipWithCard, "Gift Wrap", 4.75);
    
    cout << "Description: " << giftTulip->description() << endl;
    cout << "Price: $" << giftTulip->price() << endl;
    cout << "Name: " << giftTulip->getName() << endl;
    cout << endl;
    
    cout << "TEST 4: Different Decoration Combination" << endl;
    cout << "---------------------------------------" << endl;
    Plant* basicOrchid = new BasicPlant("Orchid", "Elegant white orchid", 25.00);
    Plant* orchidWithCard = new CardDecorator(basicOrchid, "Congratulations!", 3.25);
    Plant* wrappedOrchid = new WrapDecorator(orchidWithCard, "Premium Wrap", 7.50);
    
    cout << "Description: " << wrappedOrchid->description() << endl;
    cout << "Price: $" << wrappedOrchid->price() << endl;
    cout << endl;
    
    cout << "TEST 5: Cloning Decorated Plants" << endl;
    cout << "-------------------------------" << endl;
    Plant* clonedGiftTulip = giftTulip->clone();
    cout << "Original: " << giftTulip->description() << endl;
    cout << "Cloned:   " << clonedGiftTulip->description() << endl;
    cout << "Original Price: $" << giftTulip->price() << endl;
    cout << "Cloned Price:   $" << clonedGiftTulip->price() << endl;
    cout << "Clone successful: " << (giftTulip->price() == clonedGiftTulip->price() ? "YES" : "NO") << endl;
    cout << endl;
    
    cout << "TEST 6: Price Breakdown" << endl;
    cout << "----------------------" << endl;
    Plant* basic = new BasicPlant("Cactus", "Desert cactus", 8.00);
    cout << "Basic plant: $" << basic->price() << endl;
    
    Plant* withPot = new PotDecorator(basic, "Plastic", 3.00);
    cout << " + Pot: $" << withPot->price() << " (+$3.00)" << endl;
    
    Plant* withCard = new CardDecorator(withPot, "Happy Birthday", 2.50);
    cout << " + Card: $" << withCard->price() << " (+$2.50)" << endl;
    
    Plant* withWrap = new WrapDecorator(withCard, "Basic Wrap", 2.00);
    cout << " + Wrap: $" << withWrap->price() << " (+$2.00)" << endl;
    
    cout << "Total: $" << withWrap->price() << endl;
    cout << endl;
   
    
    cout << "CLEANUP" << endl;
    cout << "-------" << endl;
    delete potRose;           
    delete giftTulip;        
    delete wrappedOrchid;      
    delete clonedGiftTulip;   
    delete withWrap;          
    
    cout << "All plants deleted successfully!" << endl;
  
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
    
