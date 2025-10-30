#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H
#include "Plant.h"
#include <string>
using namespace std;

class Plant;
class PlantLifeCycleState;

class PlantObserver {
public:
    virtual ~PlantObserver() = default;
    
    virtual void onPlantStateChanged(Plant* plant) = 0;
    virtual void onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) = 0;
    virtual void onSeasonChanged(Plant* plant, string newSeason) = 0;
    virtual void onCareStrategyChanged(Plant* plant) = 0;
};

#endif