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
#include "Rose.h"

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

int main() {
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