/**
 * @file CaresSchedulerObserver.cpp
 * @brief Implementation of CareSchedulerObserver for plant monitoring
 * @author COS214 Final Project Team
 * @date 2025
 */

#include "CareScheduleObserver.h"
void CareSchedulerObserver::onPlantStateChanged(Plant* plant) {
    std::cout << "[CareScheduler] Plant state changed: " 
              << plant->getName() << " is now in state: " 
              << plant->getStateText() << std::endl;
}

void CareSchedulerObserver::onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) {
    std::cout << "[CareScheduler] Life cycle changed for: " 
              << plant->getName() << std::endl;
}

void CareSchedulerObserver::onSeasonChanged(Plant* plant, string newSeason) {
    std::cout << "[CareScheduler] Season changed: " 
              << plant->getName() << " now in season: " 
              << newSeason << std::endl;
}

void CareSchedulerObserver::onCareStrategyChanged(Plant* plant) {
    std::cout << "[CareScheduler] Care strategy updated for: " 
              << plant->getName() << std::endl;
}
