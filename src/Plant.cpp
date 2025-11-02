
#ifndef PLANT_CPP_DOC
/**
 * @file Plant.cpp
 * @brief Core Plant base class method implementations.
 */
#define PLANT_CPP_DOC
#endif

#include "Plant.h"
#include "PlantObserver.h"
#include <algorithm>

Plant::Plant(string name, string careType, string state, string season,
             CareStrategy *strategy, PlantLifeCycleState *life)
    : name(name), careType(careType), state(state), season(season),
      careStrategy(strategy), lifeCycle(life) {}

Plant::Plant()
    : name(""), careType(""), state(""), season(""), careStrategy(nullptr),
      lifeCycle(nullptr) {}

Plant::~Plant() {
  if (careStrategy) {
    delete careStrategy;
  }
  if (lifeCycle) {
    delete lifeCycle;
  }
}

string Plant::getCareType() { return careType; }

string Plant::getStateText() { return state; }

string Plant::getSeason() { return season; }

CareStrategy *Plant::getCareStrategy() { return careStrategy; }

PlantLifeCycleState *Plant::getLifeCycle() { return lifeCycle; }

void Plant::setName(string n) { name = n; }
void Plant::setCareType(string t) {
  careType = t;
  notifyCareStrategyChanged();
}

// double Plant::price() { return price_; }

void Plant::setPrice(double newPrice) { price_ = newPrice; }

void Plant::setStateText(string s) {
  state = s;
  notifyStateChanged();
}
void Plant::setSeason(string s) {
  season = s;
  notifySeasonChanged(s);
}
void Plant::setCareStrategy(CareStrategy *cs) {
  if (!cs)
    return;
  if (careStrategy && careStrategy != cs) {
    delete careStrategy;
  }
  careStrategy = cs;
  cs->applyCare(this);
  notifyCareStrategyChanged();
}
void Plant::setLifeCycle(PlantLifeCycleState *st) {
  if (!st)
    return;
  if (lifeCycle && lifeCycle != st)
    delete lifeCycle;
  lifeCycle = st;
  notifyLifeCycleChanged(st);
}

void Plant::attach(PlantObserver *observer) {
  if (!observer)
    return;
  observers.push_back(observer);
}

void Plant::detach(PlantObserver *observer) {
  if (!observer)
    return;
  observers.erase(std::remove(observers.begin(), observers.end(), observer),
                  observers.end());
}

void Plant::notifyStateChanged() {}

void Plant::notifyLifeCycleChanged(PlantLifeCycleState *newState) {
  if (!newState)
    return;
  for (auto observer : observers) {
    observer->onLifeCycleChanged(this, newState);
  }
}

void Plant::notifySeasonChanged(string newSeason) {}

void Plant::notifyCareStrategyChanged() {}

void Plant::takeCare() {
  if (careStrategy) {
    careStrategy->applyCare(this);
  }
}
