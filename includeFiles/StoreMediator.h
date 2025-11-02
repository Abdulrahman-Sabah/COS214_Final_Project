/**
 * @file StoreMediator.h
 * @brief Abstract Mediator interface for coordinating communication between
 * shop participants
 * @author COS214
 * @date 2025
 */

#ifndef STOREMEDIATOR_H
#define STOREMEDIATOR_H

#include <string>

#include "Plant.h"

class Commands;

class StoreMediator {
public:
  /**
   * @brief Notify the mediator that an event occurred
   * @param plant The object sending the notification
   * @param event  The type of event (e.g., "CustomerRequest", "DeliveryReady")
   * @param cmd    Optional command data related to the event
   */
  virtual void notify(Plant *plant, const std::string &event) = 0;
  virtual ~StoreMediator() = default;
};

#endif