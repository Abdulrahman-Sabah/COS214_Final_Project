#include <iostream>
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
    return 0;
}
