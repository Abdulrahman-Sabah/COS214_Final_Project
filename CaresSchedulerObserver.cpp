#include "CareSchedulerObserver.h"
#include "Plant.h"

void CareSchedulerObserver::onPlantStateChanged(Plant* plant) {
    cout << "[Scheduler] Updating care schedule for '" << plant->getName() 
         << "' based on state: " << plant->getStateText() << endl;
}

void CareSchedulerObserver::onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) {
    cout << "[Scheduler] Adjusting watering frequency for '" << plant->getName() 
         << "' due to lifecycle change" << endl;
}

void CareSchedulerObserver::onSeasonChanged(Plant* plant, string newSeason) {
    cout << "[Scheduler] Modifying care routine for '" << plant->getName() 
         << "' for season: " << newSeason << endl;
}

void CareSchedulerObserver::onCareStrategyChanged(Plant* plant) {
    cout << "[Scheduler] Recalculating care tasks for '" << plant->getName() 
         << "' with new strategy" << endl;
}