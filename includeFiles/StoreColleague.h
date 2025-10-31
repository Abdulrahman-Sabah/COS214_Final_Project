
#ifndef STORECOLLEAGUE_H
#define STORECOLLEAGUE_H

#include <string>

#include "StoreMediator.h"

class StoreColleague {
 protected:
  StoreMediator* mediator;

 public:
  StoreColleague() = default;
  explicit StoreColleague(StoreMediator* m) : mediator(m) {}
  virtual ~StoreColleague() = default;

  void setMediator(StoreMediator* m) { mediator = m; }
  StoreMediator* getMediator() const { return mediator; }

  /**
   * @brief Receive notifications from the mediator
   * @param event The event type or message
   */
  virtual void receive(const std::string& event) = 0;
};

#endif