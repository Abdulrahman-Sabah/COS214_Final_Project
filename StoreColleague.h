#ifndef STORECOLLEAGUE_H
#define STORECOLLEAGUE_H

#include "StoreMediator.h"


class StoreColleague {
public:
    StoreMediator* mediator = nullptr;

public:
    explicit StoreColleague(StoreMediator* m = nullptr) : mediator(m) {}
    virtual ~StoreColleague() = default;

    void setMediator(StoreMediator* m) { mediator = m; }
    StoreMediator* getMediator() const { return mediator; }   

    virtual void receive(const std::string& event) = 0;
};

#endif
