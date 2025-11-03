
#ifndef CARESCHEDULEROBSERVER_H
#define CARESCHEDULEROBSERVER_H

/**
 * @file CareScheduleObserver.h
 * @brief Observer for plant care scheduling notifications
 * @author Git it done group members
 * @date 10-2025
 */
#include <iostream>

#include "Handler.h"
#include "PlantObserver.h"
/**
 * @class CareSchedulerObserver
 * @brief Concrete observer that monitors plant state changes for care
 * scheduling
 * @details CareSchedulerObserver implements the Observer pattern to track
 * changes in plant lifecycle states and care strategies. It responds to these
 * changes by updating care schedules and updating the important changes.
 */
class CareSchedulerObserver : public PlantObserver {
public:
  Handler *handler_;

public:
  /**
   * @brief Constructor with handler chain head
   * @param chainHead The head of the Handler chain used to forward requests
   */
  explicit CareSchedulerObserver(Handler *chainHead) : handler_(chainHead) {}
  ~CareSchedulerObserver();
  /**
   * @brief Called when a plant's lifecycle state changes
   * @param plant Pointer to the plant with lifecycle change
   * @param newState Pointer to the new lifecycle state
   * @details This method responds to plant lifecycle state changes and updates
   * care schedules accordingly.
   */
  void onLifeCycleChanged(Plant *plant, PlantLifeCycleState *newState) override;

  /**
   * @brief Called when a plant's care strategy changes
   * @param plant Pointer to the plant with strategy change
   * @param newStrategy Pointer to the new CareStrategy
   * @details This method responds to care strategy changes in the plant and
   * updates care schedules accordingly.
   */
  void onCareStrategyChanged(Plant *plant, CareStrategy *newStrategy) override;

  /**
   * @brief default constructor
   */
  CareSchedulerObserver();

  /**
   * @brief Set next handler in chain
   * @param newHandler Handler pointer
   */
  void setHandler(Handler *newHandler);
};

#endif