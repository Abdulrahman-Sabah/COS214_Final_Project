/**
 * @file CareScheduleObserver.h
 * @brief Observer for plant care scheduling notifications.
 *
 * Implements the Observer pattern to monitor plant lifecycle and care strategy
 * changes. CareSchedulerObserver forwards responsibilities to the appropriate
 * staff member using the Chain of Responsibility pattern via a Handler chain.
 *
 * @author
 * COS214 Final Project Team
 * @date 2025
 */

#ifndef CARECHEDULEROBSERVER_H
#define CARECHEDULEROBSERVER_H

#include <iostream>
#include "Handler.h"
#include "PlantObserver.h"

/**
 * @class CareSchedulerObserver
 * @brief Concrete observer that monitors plant state changes for care scheduling.
 *
 * CareSchedulerObserver implements:
 * - Observer Pattern → reacts to lifecycle & care strategy updates
 * - Chain of Responsibility → forwards care actions to staff handlers
 *
 * It ensures the plant receives appropriate care action depending on:
 * - Lifecycle state changes (Seedling → Growing → Mature, etc.)
 * - Care strategy adjustments (watering, pruning, etc.)
 */
class CareSchedulerObserver : public PlantObserver {
private:
    /**
     * @brief Pointer to the first care handler in the chain.
     *
     * Used to forward requests down the Chain of Responsibility.
     */
    Handler* handler_;

public:
    /**
     * @brief Default constructor for proper initialization.
     */
    CareSchedulerObserver();

    /**
     * @brief Construct with Handler chain head initialization.
     *
     * @param chainHead The first Handler in the Chain of Responsibility.
     */
    explicit CareSchedulerObserver(Handler* chainHead);

    /**
     * @brief Virtual destructor for safe polymorphic cleanup.
     */
    ~CareSchedulerObserver() override;

    /**
     * @brief Triggered when a plant’s lifecycle state changes.
     *
     * Updates scheduling and forwards to Handler chain if necessary.
     *
     * @param plant The affected plant.
     * @param newState The new lifecycle state assigned to the plant.
     */
    void onLifeCycleChanged(Plant* plant, PlantLifeCycleState* newState) override;

    /**
     * @brief Triggered when a plant’s care strategy changes.
     *
     * Adjusts future care routines and logs strategy updates.
     *
     * @param plant The affected plant.
     * @param newStrategy Updated care strategy assigned to the plant.
     */
    void onCareStrategyChanged(Plant* plant, CareStrategy* newStrategy) override;

    /**
     * @brief Assign a new Handler chain.
     *
     * @param newHandler Root handler of Chain of Responsibility.
     */
    void setHandler(Handler* newHandler);
};

#endif // CARECHEDULEROBSERVER_H
