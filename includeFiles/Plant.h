/**
 * @file Plant.h
 * @brief Abstract base class for all plants in the greenhouse management system
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef PLANT_H
#define PLANT_H
#include "CareStrategy.h"
#include <string>
#include <vector>
using namespace std;

// Forward declarations
class CareStrategy;
class PlantLifeCycleState;
class PlantObserver;

/**
 * @class Plant
 * @brief Abstract base class representing a plant in the greenhouse system
 *
 * The Plant class implements multiple design patterns:
 * - Observer pattern: Notifies observers when plant state changes
 * - Strategy pattern: Uses different care strategies for different plant types
 * - State pattern: Manages plant lifecycle states
 * - Prototype pattern: Supports cloning of plant objects
 *
 * This class serves as the core component that integrates with various
 * subsystems including care management, lifecycle tracking, and inventory.
 */
class Plant {
private:
  string name; /**< Name of the plant */
  string
      careType; /**< Type of care required (e.g., "Low", "Moderate", "High") */
  string state;
  string season;
  CareStrategy *careStrategy;
  PlantLifeCycleState *lifeCycle;
  vector<PlantObserver *> observers;

protected:
  void notifyStateChanged();
  void notifyLifeCycleChanged(PlantLifeCycleState *newState);
  void notifySeasonChanged(string newSeason);
  void notifyCareStrategyChanged();

public:
  Plant(string name, string careType, string state, string season,
        CareStrategy *strategy, PlantLifeCycleState *life);

  Plant();

  virtual ~Plant() = default;

  virtual string description() = 0;
  virtual double price() = 0;
  virtual Plant *clone() = 0;

  virtual string getName() { return name; };
  string getCareType();
  string getStateText();
  string getSeason();
  CareStrategy *getCareStrategy();
  PlantLifeCycleState *getLifeCycle();

  void setName(string n);
  void setCareType(string t);
  void setStateText(string s);
  void setSeason(string s);
  void setCareStrategy(CareStrategy *cs);
  void setLifeCycle(PlantLifeCycleState *st);

  void attach(PlantObserver *observer);
  void detach(PlantObserver *observer);

  void takeCare();
};

#endif