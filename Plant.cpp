#include "Plant.h"

Plant::Plant(std::string n, std::string c, std::string s, std::string se, CareStrategy* strategy, PlantLifeCycleState* life) 
    : name(n), careType(c), state(s), season(se) /*, careStrategy(strategy)*/, lifeCycleState(life) {
}

Plant::~Plant() {}

std::string Plant::getName() { return name; }

std::string Plant::getCareType() { return careType; }

std::string Plant::getStateText() { return state; }

std::string Plant::getSeason() { return season; }

void Plant::setName(std::string n) { name = n; }

void Plant::setCareType(std::string t) { careType = t; }

void Plant::setStateText(std::string s) { state = s; }

void Plant::setSeason(std::string s) { season = s; }

PlantLifeCycleState* Plant::getLifeCycleState() { return lifeCycleState; }

std::vector<Plant*> Plant::getPlants() { return plants; }

void Plant::setLifeCycle(PlantLifeCycleState* st) { lifeCycleState = st; }

void Plant::setState(PlantLifeCycleState* s) { lifeCycleState = s; }

std::list<Plant*> Plant::all() { 
    std::list<Plant*> plants;
    for (int i = 0; i < this->plants.size(); i++) {
        plants.push_back(this->plants[i]);
    }
    return plants;
}