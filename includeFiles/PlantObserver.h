
#ifndef PLANTOBSERVER_H
#define PLANTOBSERVER_H

/**
 * @file PlantObserver.h
 * @brief Abstract observer interface for the Observer pattern implementation
 * @author Git it done group members
 * @date 2024
 */

#include <string>

#include "CareStrategy.h"
#include "Plant.h"
using namespace std;

class Plant;
class PlantLifeCycleState;

/**
 * @class PlantObserver
 * @brief Abstract observer class for monitoring Plant state changes
 * @details Defines the interface for the Observer pattern, allowing objects
 * to be notified when plants undergo changes such as lifecycle state changes or
 * care strategy changes.
 */
class PlantObserver {
public:
  /**
   * @brief Virtual destructor for proper cleanup
   */
  virtual ~PlantObserver() = default;

  /**
   * @brief Called when a plant's lifecycle state changes
   * @param plant The plant whose lifecycle changed
   * @param newState The new lifecycle state
   */
  virtual void onLifeCycleChanged(Plant *plant,
                                  PlantLifeCycleState *newState) = 0;

  /**
   * @brief Called when a plant's care strategy changes
   * @param plant The plant whose care strategy changed
   * @param newStrategy The new care strategy
   */
  virtual void onCareStrategyChanged(Plant *plant,
                                     CareStrategy *newStrategy) = 0;
};

#endif