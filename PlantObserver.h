/**
 * @file PlantObserver.h
 * @brief Abstract observer interface for the Observer pattern implementation
 * @author COS214 Students
 * @date 2024
 */

#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H
#include "Plant.h"
#include "CareStrategy.h"
#include <string>
using namespace std;

class Plant;
class PlantLifeCycleState;

/**
 * @class PlantObserver
 * @brief Abstract observer class for monitoring Plant state changes
 * 
 * This class defines the interface for the Observer pattern, allowing objects
 * to be notified when plants undergo various state changes such as lifecycle
 * transitions, season changes, or care strategy modifications.
 */
class PlantObserver {
public:
    /**
     * @brief Virtual destructor for proper cleanup
     */
    virtual ~PlantObserver() = default;
    
    /**
     * @brief Called when a plant's general state changes
     * @param plant The plant that changed state
     */
    //virtual void onPlantStateChanged(Plant* plant,CareStrategy* CareStrategyOfPlant) = 0;
    
    /**
     * @brief Called when a plant's lifecycle state changes
     * @param plant The plant whose lifecycle changed
     * @param newState The new lifecycle state
     */
    virtual void onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) = 0;
    
    /**
     * @brief Called when a plant's season changes
     * @param plant The plant whose season changed
     * @param newSeason The new season
     */
    
    /**
     * @brief Called when a plant's care strategy changes
     * @param plant The plant whose care strategy changed
     */
    virtual void onCareStrategyChanged(Plant* plant,CareStrategy* newStrategy) = 0;
};

#endif