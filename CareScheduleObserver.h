/**
 * @file CareScheduleObserver.h
 * @brief Observer for plant care scheduling notifications
 * @author COS214 Final Project Team
 * @date 2025
 */

#ifndef CARESCHEDULEROBSERVER_H
#define CARESCHEDULEROBSERVER_H
#include "PlantObserver.h"

#include <iostream>

/**
 * @class CareSchedulerObserver
 * @brief Concrete observer that monitors plant state changes for care scheduling
 * 
 * CareSchedulerObserver implements the Observer pattern to track changes in
 * plant states, lifecycle phases, seasons, and care strategies. It responds
 * to these changes by updating care schedules and logging important events.
 */
class CareSchedulerObserver : public PlantObserver {
public:
    /**
     * @brief Called when a plant's general state changes
     * @param plant Pointer to the plant that changed state
     * 
     * This method is notified when a plant's basic state information
     * changes, allowing the care scheduler to adjust care plans accordingly.
     */
    void onPlantStateChanged(Plant* plant) override;
    
    /**
     * @brief Called when a plant's lifecycle state changes
     * @param plant Pointer to the plant with lifecycle change
     * @param newState Pointer to the new lifecycle state
     * 
     * This method responds to plant lifecycle transitions (e.g., seedling
     * to growing, growing to mature) and updates care schedules accordingly.
     */
    void onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) override;
    
    /**
     * @brief Called when a plant's seasonal context changes
     * @param plant Pointer to the plant with season change
     * @param newSeason String representing the new season
     * 
     * This method adjusts care schedules based on seasonal changes that
     * affect plant care requirements.
     */
    void onSeasonChanged(Plant* plant, string newSeason) override;
    
    /**
     * @brief Called when a plant's care strategy changes
     * @param plant Pointer to the plant with strategy change
     * 
     * This method responds to changes in plant care strategies and
     * updates scheduling accordingly.
     */
    void onCareStrategyChanged(Plant* plant) override;
};

#endif
