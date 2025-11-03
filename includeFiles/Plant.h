#ifndef PLANT_H
#define PLANT_H

#include "CareStrategy.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @file Plant.h
 * @brief Abstract base class for all plants.
 * @author Git it done group members
 * @date 10-2025
 */

class CareStrategy;
class PlantLifeCycleState;
class PlantObserver;

class Plant {
private:
  /** @brief Plant attributes */
  string name;
  string careType;
  string state;
  string season;
  CareStrategy *careStrategy;
  PlantLifeCycleState *lifeCycle;
  vector<PlantObserver *> observers;
  double price_;

protected:
  /// @brief Notify when lifecycle state changes
  void notifyStateChanged();

  /**
   * @brief Notify lifecycle change
   * @param newState New lifecycle state
   */
  void notifyLifeCycleChanged(PlantLifeCycleState *newState);

  /**
   * @brief Notify season change
   * @param newSeason Season string
   */
  void notifySeasonChanged(string newSeason);

  /// @brief Notify care strategy changed
  void notifyCareStrategyChanged();

public:
  /// @return Type name
  virtual std::string getType() const { return "Plant"; }

  /**
   * @brief Full constructor
   * @param name Plant name
   * @param careType Care strategy text
   * @param state Lifecycle state text
   * @param season Season text
   * @param strategy CareStrategy pointer
   * @param life PlantLifeCycleState pointer
   */
  Plant(string name, string careType, string state, string season,
        CareStrategy *strategy, PlantLifeCycleState *life);

  /// @brief Default constructor
  Plant();

  /// @brief Destructor
  virtual ~Plant();

  /// @return Description text
  virtual string description() = 0;

  /// @return Price value
  virtual double price() = 0;

  /// @return Cloned plant
  virtual Plant *clone() = 0;

  /// @return Plant name
  virtual string getName() { return name; }

  /// @return Care type text
  string getCareType();

  /// @return Lifecycle state text
  string getStateText();

  /// @return Season text
  string getSeason();

  /// @return Pointer to care strategy
  CareStrategy *getCareStrategy();

  /// @return Pointer to lifecycle state
  PlantLifeCycleState *getLifeCycle();

  /// @param n New name
  void setName(string n);

  /// @param t New care type
  void setCareType(string t);

  /// @param p New price value
  void setPrice(double p);

  /// @param s New state text
  void setStateText(string s);

  /// @param s New season text
  void setSeason(string s);

  /// @param cs CareStrategy pointer
  void setCareStrategy(CareStrategy *cs);

  /// @param st PlantLifeCycleState pointer
  void setLifeCycle(PlantLifeCycleState *st);

  /**
   * @brief Add observer
   * @param observer Observer to attach
   */
  void attach(PlantObserver *observer);

  /**
   * @brief Remove observer
   * @param observer Observer to detach
   */
  void detach(PlantObserver *observer);

  /**
   * @brief Perform care via current strategy
   */
  void takeCare();
};

#endif
