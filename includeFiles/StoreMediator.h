
#ifndef STOREMEDIATOR_H
#define STOREMEDIATOR_H

/**
 * @file StoreMediator.h
 * @brief Mediator interface for coordinating communication.
 */

#include "Plant.h"
#include <string>

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
  virtual void notify(Plant *plant, const std::string &event) = 0;

  /// @brief Virtual destructor
  virtual ~StoreMediator() = default;
};

#endif // STOREMEDIATOR_H
