#ifndef PLANT_H
#define PLANT_H
#include <string>
#include <vector>

#include "CareStrategy.h"
using namespace std;

/**
 * @file Plant.h
 * @brief Abstract base class representing a plant in the nursery.
 *
 * Plant declares the main interface for all concrete plant types used in the
 * project (description, price, cloning) and provides observer and lifecycle
 * integration points.
 */

class CareStrategy;
class PlantLifeCycleState;
class PlantObserver;

class Plant {
private:
  string name;
  string careType;
  string state;
  string season;
  CareStrategy *careStrategy;
  PlantLifeCycleState *lifeCycle;
  vector<PlantObserver *> observers;
  double price_;

protected:
  void notifyStateChanged();
  void notifyLifeCycleChanged(PlantLifeCycleState *newState);
  void notifySeasonChanged(string newSeason);
  void notifyCareStrategyChanged();

public:
  /** @brief Return runtime type name (override in subclasses) */
  virtual std::string getType() const { return "Plant"; }

  /** @brief Construct a Plant with full parameters */
  Plant(string name, string careType, string state, string season,
        CareStrategy *strategy, PlantLifeCycleState *life);

  Plant();

  virtual ~Plant();

  /** @brief Get a textual description of this plant (pure virtual) */
  virtual string description() = 0;

  /** @brief Get the price of the plant (pure virtual) */
  virtual double price() = 0;

  /** @brief Clone the plant (pure virtual) */
  virtual Plant *clone() = 0;

  virtual string getName() { return name; };
  string getCareType();
  string getStateText();
  string getSeason();
  CareStrategy *getCareStrategy();
  PlantLifeCycleState *getLifeCycle();

  void setName(string n);
  void setCareType(string t);
  void setPrice(double p);
  void setStateText(string s);
  void setSeason(string s);
  void setCareStrategy(CareStrategy *cs);
  void setLifeCycle(PlantLifeCycleState *st);

  void attach(PlantObserver *observer);
  void detach(PlantObserver *observer);

  /** @brief Convenient wrapper that delegates to the configured CareStrategy */
  void takeCare();
};

#endif