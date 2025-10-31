#ifndef PLANT_H
#define PLANT_H
#include <string>
#include <vector>

#include "CareStrategy.h"
using namespace std;

class CareStrategy;
class PlantLifeCycleState;
class PlantObserver;

class Plant {
 private:
  string name;
  string careType;
  string state;
  string season;
  CareStrategy* careStrategy;
  PlantLifeCycleState* lifeCycle;
  vector<PlantObserver*> observers;
  double price_;

 protected:
  void notifyStateChanged();
  void notifyLifeCycleChanged(PlantLifeCycleState* newState);
  void notifySeasonChanged(string newSeason);
  void notifyCareStrategyChanged();

 public:
  virtual std::string getType() const { return "Plant"; }
  Plant(string name, string careType, string state, string season,
        CareStrategy* strategy, PlantLifeCycleState* life);

  Plant();

  virtual ~Plant() = default;

  virtual string description() = 0;
  virtual double price() = 0;
  virtual Plant* clone() = 0;

  virtual string getName() { return name; };
  string getCareType();
  string getStateText();
  string getSeason();
  CareStrategy* getCareStrategy();
  PlantLifeCycleState* getLifeCycle();

  void setName(string n);
  void setCareType(string t);
  void setPrice(double p);
  void setStateText(string s);
  void setSeason(string s);
  void setCareStrategy(CareStrategy* cs);
  void setLifeCycle(PlantLifeCycleState* st);

  void attach(PlantObserver* observer);
  void detach(PlantObserver* observer);

  void takeCare();
};

#endif