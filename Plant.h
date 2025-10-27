#ifndef PLANT_H
#define PLANT_H
#include "CareStrategy.h"
#include <string>
#include <vector>
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

protected:
    void notifyStateChanged();
    void notifyLifeCycleChanged(PlantLifeCycleState* newState);
    void notifySeasonChanged(string newSeason);
    void notifyCareStrategyChanged();

public:
    Plant(string name, string careType, string state, string season, 
          CareStrategy* strategy, PlantLifeCycleState* life);
    
    Plant();
    
    virtual ~Plant();
    
    virtual string description() = 0;
    virtual double price() = 0;
    virtual Plant* clone() = 0;
    
    virtual string getName(){ return name;};
    string getCareType();
    string getStateText();
    string getSeason();
    CareStrategy* getCareStrategy();
    PlantLifeCycleState* getLifeCycle();
    
    void setName(string n);
    void setCareType(string t);
    void setStateText(string s);
    void setSeason(string s);
    void setCareStrategy(CareStrategy* cs);
    void setLifeCycle(PlantLifeCycleState* st);
    
    void attach(PlantObserver* observer);
    void detach(PlantObserver* observer);

    void takeCare();
};

#endif