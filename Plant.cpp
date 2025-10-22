#include "Plant.h"
#include "PlantObserver.h"
#include <algorithm>

Plant::Plant(string name, string careType, string state, string season, 
             CareStrategy* strategy, PlantLifeCycleState* life)
    : name(name), careType(careType), state(state), season(season),
      careStrategy(strategy), lifeCycle(life) {}

Plant::Plant() : name(""), careType(""), state(""), season(""),
                 careStrategy(nullptr), lifeCycle(nullptr) {}

string Plant::getName() { return name; }
string Plant::getCareType() { return careType; }
string Plant::getStateText() { return state; }
string Plant::getSeason() { return season; }
CareStrategy* Plant::getCareStrategy() { return careStrategy; }
PlantLifeCycleState* Plant::getLifeCycle() { return lifeCycle; }

void Plant::setName(string n) {
    name = n;
}

void Plant::setCareType(string t) {
    careType = t;
}

void Plant::setStateText(string s) {
    state = s;
    notifyStateChanged();
}

void Plant::setSeason(string s) {
    string oldSeason = season;
    season = s;
    notifySeasonChanged(s);
}

void Plant::setCareStrategy(CareStrategy* cs) {
    careStrategy = cs;
    notifyCareStrategyChanged();
}

void Plant::setLifeCycle(PlantLifeCycleState* st) {
    lifeCycle = st;
    notifyLifeCycleChanged(st);
}

void Plant::attach(PlantObserver* observer) {
    observers.push_back(observer);
}

void Plant::detach(PlantObserver* observer) {
    observers.erase(
        remove(observers.begin(), observers.end(), observer),
        observers.end()
    );
}

void Plant::notifyStateChanged() {
    for (PlantObserver* observer : observers) {
        observer->onPlantStateChanged(this);
    }
}

void Plant::notifyLifeCycleChanged(PlantLifeCycleState* newState) {
    for (PlantObserver* observer : observers) {
        observer->onLifeCycleChanged(this, newState);
    }
}

void Plant::notifySeasonChanged(string newSeason) {
    for (PlantObserver* observer : observers) {
        observer->onSeasonChanged(this, newSeason);
    }
}

void Plant::notifyCareStrategyChanged() {
    for (PlantObserver* observer : observers) {
        observer->onCareStrategyChanged(this);
    }
}