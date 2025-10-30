
/**
 * @file Plant.cpp
 * @brief Implementation of the Plant base class
 * @author COS214 Students
 * @date 2025
 */

#include "Plant.h"
#include "PlantObserver.h"
#include <algorithm>

Plant::Plant(string name, string careType, string state, string season, 
        CareStrategy* strategy, PlantLifeCycleState* life)
        : name(name), careType(careType), state(state), season(season),
        careStrategy(strategy), lifeCycle(life) {}

Plant::Plant() : name(""), careType(""), state(""), season(""), 
        careStrategy(nullptr), lifeCycle(nullptr) {}

string Plant::getCareType() { return careType; }

string Plant::getStateText() { return state; }

string Plant::getSeason() { return season; }

CareStrategy* Plant::getCareStrategy() { return careStrategy; }

PlantLifeCycleState* Plant::getLifeCycle() { return lifeCycle; }

void Plant::setName(string n) { name = n; }
void Plant::setCareType(string t) { 
    careType = t; 
}
void Plant::setStateText(string s) { 
    state = s; 
}

void Plant::setSeason(string s) { 
    season = s; 
}
void Plant::setCareStrategy(CareStrategy* cs) { 
    if(careStrategy || careStrategy != cs) delete careStrategy;
    careStrategy = cs; 
}
void Plant::setLifeCycle(PlantLifeCycleState* st) { 
    if(lifeCycle || lifeCycle != st) delete lifeCycle;
    lifeCycle = st; 
}

void Plant::attach(PlantObserver* observer) {
    observers.push_back(observer);
}

void Plant::detach(PlantObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), 
                   observers.end());
}

Plant::~Plant() 
{
    delete lifeCycle;                  
    lifeCycle = nullptr;
    delete careStrategy;
}

void Plant::takeCare() {
    if (careStrategy) {
        careStrategy->applyCare(this);
    }
}

