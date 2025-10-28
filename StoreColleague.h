/**
 * @file StoreColleague.h
 * @brief Base class for all participants that communicate via the Mediator pattern
 * @author COS214
 * @date 2025
 */

#ifndef STORECOLLEAGUE_H
#define STORECOLLEAGUE_H 

#include "StoreMediator.h"
#include <string>

class StoreColleague {
protected:
    StoreMediator* mediator;

public:
    explicit StoreColleague(StoreMediator* m = nullptr) : mediator(m) {}
    virtual ~StoreColleague() = default;

    void setMediator(StoreMediator* m) { mediator = m; }

    /**
     * @brief Receive notifications from the mediator
     * @param event The event type or message
     */
    virtual void receive(const std::string& event) = 0;
};

#endif
