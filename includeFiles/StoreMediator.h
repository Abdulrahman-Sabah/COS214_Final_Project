/**
 * @file StoreMediator.h
 * @brief Mediator interface for coordinating communication.
 */

#ifndef STOREMEDIATOR_H
#define STOREMEDIATOR_H

#include <string>
#include "Plant.h"

class Commands;

/**
 * @class StoreMediator
 * @brief Handles communication between store colleagues.
 */
class StoreMediator {
public:
    /**
     * @brief Notify mediator of an event
     * @param plant Plant involved
     * @param event Event message
     */
    virtual void notify(Plant* plant, const std::string& event) = 0;

    /// Virtual destructor
    virtual ~StoreMediator() = default;
};

#endif // STOREMEDIATOR_H
