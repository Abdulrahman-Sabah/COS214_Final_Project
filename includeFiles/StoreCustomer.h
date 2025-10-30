#ifndef STORECUSTOMER_H
#define STORECUSTOMER_H

#include "StoreColleague.h"
#include "Plant.h"
#include <iostream>

class StoreCustomer : public StoreColleague {
public:
    using StoreColleague::StoreColleague;

    void requestPlant(Plant* p);
    void receive(const std::string& event) override;
};

#endif
