#ifndef CARESCHEDULEROBSERVER_H
#define CARESCHEDULEROBSERVER_H
#include "PlantObserver.h"
#include <iostream>

class CareSchedulerObserver : public PlantObserver {
public:
    void onPlantStateChanged(Plant* plant) override;
    void onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) override;
    void onSeasonChanged(Plant* plant, string newSeason) override;
    void onCareStrategyChanged(Plant* plant) override;
};

#endif
