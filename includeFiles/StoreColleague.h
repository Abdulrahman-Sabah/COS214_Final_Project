
#ifndef STORECOLLEAGUE_H
#define STORECOLLEAGUE_H

/**
 * @file StoreColleague.h
 * @brief Base class for participants in the Store mediator pattern.
 *
 * StoreColleague represents an entity (customer, delivery staff, etc.) that
 * communicates via a StoreMediator. Subclasses implement receive() to handle
 * incoming notifications.
 */

#include <string>

#include "StoreMediator.h"

class StoreColleague {
protected:
  StoreMediator *mediator; /**< Associated mediator (may be nullptr) */

public:
  StoreColleague() { mediator = nullptr; };
  explicit StoreColleague(StoreMediator *m) : mediator(m) {}
  virtual ~StoreColleague() = default;

  /** @brief Set the mediator used by this colleague */
  void setMediator(StoreMediator *m) { mediator = m; }

  /** @brief Get the configured mediator (may be nullptr) */
  StoreMediator *getMediator() const { return mediator; }

  /**
   * @brief Receive notifications from the mediator
   * @param event The event type or message
   *
   * Subclasses implement this to react to mediator notifications such as
   * "CustomerRequest" or "DeliveryReady".
   */
  virtual void receive(const std::string &event) = 0;
};

#endif