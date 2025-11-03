
#ifndef STORECOLLEAGUE_H
#define STORECOLLEAGUE_H

/**
 * @file StoreColleague.h
 * @brief Base class for participants in the Store mediator pattern.
 * @details StoreColleague represents an entity (customer, delivery staff, etc.) that
 * communicates via a StoreMediator.
 * @author Git it done group members
 * @date 10-2025
 */

#include <string>

#include "StoreMediator.h"

/**
 * @class StoreColleague
 * @brief Abstract base class for store participants in the mediator pattern.
 */
class StoreColleague {
protected:
  /** @brief Pointer to the mediator */
  StoreMediator *mediator; 

public:
  /** @brief Constructor */
  StoreColleague() { mediator = nullptr; };
  /** @brief Parameterized constructor with mediator */
  explicit StoreColleague(StoreMediator *m) : mediator(m) {}
  /** @brief Virtual destructor */
  virtual ~StoreColleague() = default;

  /** @brief Set the mediator used by this colleague */
  void setMediator(StoreMediator *m) { mediator = m; }

  /** @brief Get the configured mediator
   * @return Pointer to the mediator
   */
  StoreMediator *getMediator() const { return mediator; }

  /**
   * @brief Receive notifications from the mediator
   * @param event The event type or message
   * @details Subclasses implement this to react to mediator notifications
   */
  virtual void receive(const std::string &event) = 0;
};

#endif